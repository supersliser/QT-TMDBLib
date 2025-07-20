# Async Request Queue System

## Problem Solved

This implementation addresses the issue where multiple asynchronous requests in the QT-TMDBLib could cause data confusion. When multiple API calls were made simultaneously, responses could get mixed up because:

1. All requests shared the same `QNetworkAccessManager` instance
2. All responses came back to the same `_received` slot
3. There was no way to distinguish which response belonged to which request

## Solution

Implemented a queue-based system that ensures:

- **Sequential Processing**: Only one request is processed at a time
- **No Data Confusion**: Each response is properly matched to its request
- **Proper Resource Management**: Network connections are properly cleaned up after each request

## Implementation Details

### Key Components

1. **Request Queue**: `QQueue<RequestInfo> _m_requestQueue` - stores pending requests
2. **Request State**: `bool _m_requestInProgress` - tracks if a request is currently active
3. **Queue Processing**: `_processNextRequest()` - handles sequential request execution

### Flow

1. When `_runGetRequest()` is called, the request is added to the queue
2. If no request is in progress, `_processNextRequest()` is called immediately
3. When a response comes back in `_received()`, the current request is marked complete and the next queued request is processed

### Code Changes

**Header (`include/ASync/QTMDB.h`)**:
- Added `QQueue<RequestInfo>` for request queuing
- Added `bool _m_requestInProgress` for state tracking
- Added `_processNextRequest()` method declaration

**Implementation (`src/JSON/ASync/QTMDB.cpp`)**:
- Modified `_runGetRequest()` to use the queue instead of immediate execution
- Updated `_received()` to trigger next request processing
- Added `_processNextRequest()` to handle sequential request execution

## Testing

Created comprehensive tests in `tests/JSON/ASync/queue_system.cpp` that verify:

1. Multiple requests are queued properly
2. Only one request is processed at a time
3. The queue prevents simultaneous network requests

## Backward Compatibility

This change is fully backward compatible:
- All existing API methods work exactly the same
- All existing signals (`startedLoadingData`, `finishedLoadingData`) work as before
- No changes required to client code

## Benefits

- **Eliminates Data Confusion**: Responses are never mixed between requests
- **Better Resource Management**: Only one network connection active at a time
- **Predictable Behavior**: Requests are processed in a deterministic order
- **Thread Safety**: Queue operations are handled in the main thread