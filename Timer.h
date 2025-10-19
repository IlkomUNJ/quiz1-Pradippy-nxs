#ifndef TIMER_H
#define TIMER_H

#include <string>
#include <ctime>
using namespace std;

const time_t one_day = 86400;
const time_t one_week = 7 * one_day;

const time_t one_month = 30 * one_day;

namespace TimeUtil
{

    bool isLastKDays(time_t timestamp, int k)
    {
        time_t now = time(0);
        return difftime(now, timestamp) <= (k * one_day);
    }

    bool isToday(time_t timestamp)
    {
        return isLastKDays(timestamp, 1);
    }

    bool isLastWeek(time_t timestamp)
    {
        return isLastKDays(timestamp, 7);
    }

    bool isLastMonth(time_t timestamp)
    {
        return isLastKDays(timestamp, 30);
    }

    std::string a_time_t_to_string(time_t timestamp)
    {
        char buffer[20];
        strftime(buffer, 20, "%Y-%m-%d", localtime(&timestamp));
        return std::string(buffer);
    }
}

#endif