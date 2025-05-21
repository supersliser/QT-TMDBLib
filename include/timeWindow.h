//
// Created by t on 21/05/25.
//

#ifndef TIME_WINDOW_H
#define TIME_WINDOW_H

namespace timeWindow
{
    enum class timeWindow
    {
        day,
        week,
    };

    inline std::string_view to_string(const timeWindow& t)
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
