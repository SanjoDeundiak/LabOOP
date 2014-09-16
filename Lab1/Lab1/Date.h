#pragma once
#include <cstdint>
#include <ctime>
#include <iostream>

class Date
{
    int m_year, m_month, m_day;

public:
    friend std::ostream &operator<<(std::ostream &os, const Date& date); // For output

    // Constructors
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

    // Getters
    int GetYear() const  { return m_year;  }
    int GetMonth() const { return m_month; }
    int GetDay() const   { return m_day;   }

    // Setters
    Date& setYear(int year)   { m_year = year;   return *this; }
    Date& setMonth(int month) { m_month = month; return *this; }
    Date& setDay(int day)     { m_day = day;     return *this; }

    // Destructor
    virtual ~Date() { }
};

// Output
std::ostream &operator<<(std::ostream &os, const Date& date)
{
    os << date.m_day << '.'
        << date.m_month << '.'
        << date.m_year;

    return os.flush();
}