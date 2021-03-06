#pragma once
#include <ctime>
#include <istream>
#include "Trace.h"

class Date
{
    int m_year, m_month, m_day;

public:
    friend std::ostream &operator<<(std::ostream &os, const Date& date); // For output

    // Constructors
    Date()
    {
        TRACE_ME;
        std::time_t t = time(0);
        tm now;
        localtime_s(&now, &t);

        m_year = now.tm_year + 1900;
        m_month = now.tm_mon + 1;
        m_day = now.tm_mday;
    }

    Date(int year, int month, int day) :
        m_year(year), m_month(month), m_day(day)
    {
        TRACE_ME;
    }

    Date(const Date& other) :
        m_year(other.m_year),
        m_month(other.m_month),
        m_day(other.m_day)
    {
        TRACE_ME;
    }

    // Assignment operator
    Date& operator=(const Date& other)
    {
        TRACE_ME;
        if (this == &other)
            return *this;
        m_year = other.m_year;
        m_month = other.m_month;
        m_day = other.m_day;

        return *this;
    }

    // Getters
    int GetYear() const  { return m_year;  }
    int GetMonth() const { return m_month; }
    int GetDay() const   { return m_day;   }

    // Setters
    Date& setYear(int year)   { m_year = year;   return *this; }
    Date& setMonth(int month) { m_month = month; return *this; }
    Date& setDay(int day)     { m_day = day;     return *this; }

    static Date Interactive(std::istream& is)
    {
        int d, m, y;

        do
        {
            if (!is)
            {
                is.clear();
                is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            is >> d;
            is >> m;
            is >> y;
        } while (!is);

        return Date(y, m, d);
    }

    // Destructor
    virtual ~Date()
    {
        TRACE_ME;
    }
};