//
// Created by t on 21/05/25.
//

#ifndef TIME_WINDOW_H
#define TIME_WINDOW_H

namespace tmdb::timeWindow
{
    enum class timeWindow
    {
        day,
        week,
    };

    inline std::string to_string(const timeWindow& t)
    {
        switch (t)
        {
        case timeWindow::day:
            return "day";
        case timeWindow::week:
            return "week";
        default: return "day";
        }
    }
}

#endif //TIME_WINDOW_H
