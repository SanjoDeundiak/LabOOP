#pragma once
#include <cstdint>
#include <ctime>
#include <iostream>

class Date
{
    int m_year, m_month, m_day;

public:
    Date()
    {
        std::time_t time(0);
        tm now;
        localtime_s(&now, &time);

        m_year = now.tm_year + 1900;
        m_month = now.tm_mon;
        m_day = now.tm_mday;
    }

    Date(int year, int month, int day) :
        m_year(year), m_month(month), m_day(day)
    { }

    Date(const Date& other) :
        m_year(other.m_year), m_month(other.m_month),
        m_day(other.m_day)
    { }

    int year() const  { return m_year;  }
    int month() const { return m_month; }
    int day() const   { return m_day;   }

    Date& setYear(int year)   { m_year = year;   return *this; }
    Date& setMonth(int month) { m_month = month; return *this; }
    Date& setDay(int day)     { m_day = day;     return *this; }

    virtual ~Date() { }
};

std::ostream &operator<<(std::ostream &os, const Date& date)
{
    os << date.day() << '.'
        << date.month() << '.'
        << date.year();

    return os.flush();
}