#pragma once
#include <string>
#include <ostream>
#include "Trace.h"

enum class Responsibility
{
    None,
    Worker,
    Manager,
    Employer
};

class Position
{
    // Constants
    static const size_t MAX_NAME = 250;
    static const char* DEFAULT_TITLE;

    char* m_title;
    Responsibility m_responsibility;
    float m_salary;

public:
    friend std::ostream& operator<<(std::ostream& os, const Position& position); // For output

    // Constructors
    Position() :
        m_title(nullptr), m_salary(0),
        m_responsibility(Responsibility::None)
    {
        TRACE_ME;
    }

    Position(const char* title, Responsibility responsibility, float salary) :
        m_responsibility(responsibility), m_salary(salary)
    {
        TRACE_ME;
        if (!title)
        {
            m_title = nullptr;
            return;
        }

        size_t length = strnlen_s(title, MAX_NAME) + 1;
        m_title = new char[length];
        strcpy_s(m_title, length, title);
    }

    Position(const Position& other) :
        m_responsibility(other.m_responsibility), m_salary(other.m_salary)
    {
        TRACE_ME;
        if (!other.m_title)
        {
            m_title = nullptr;
            return;
        }

        size_t length = strnlen_s(other.m_title, MAX_NAME) + 1;
        m_title = new char[length];
        strcpy_s(m_title, length, other.m_title);
    }

    Position(Position&& other) :
        m_responsibility(other.m_responsibility), m_salary(other.m_salary)
    {
        TRACE_ME;
        m_title = other.m_title;
        other.m_title = nullptr;
    }

    // Assignment operators
    Position& operator=(const Position& other)
    {
        TRACE_ME;
        if (this == &other)
            return *this;

        m_salary = other.m_salary;
        m_responsibility = other.m_responsibility;

        delete[] m_title;
        if (!other.m_title)
        {
            m_title = nullptr;
            return *this;
        }

        size_t length = strnlen_s(other.m_title, MAX_NAME) + 1;
        m_title = new char[length];
        strcpy_s(m_title, length, other.m_title);
        return *this;
    }

    Position& operator=(Position&& other)
    {
        TRACE_ME;
        m_salary = other.m_salary;
        m_responsibility = other.m_responsibility;

        delete[] m_title;
        m_title = other.m_title;
        other.m_title = nullptr;

        return *this;
    }

    // Getters
    const char* GetTitle() const             { return m_title;          }
    Responsibility GetResponsibility() const { return m_responsibility; }
    float GetSalary() const                  { return m_salary;         }

    // Setters
    Position& setTitle(const char* title)
    {
        delete[] m_title;
        if (!title)
        {
            m_title = nullptr;
            return *this;
        }

        size_t length = strnlen_s(title, MAX_NAME) + 1;
        m_title = new char[length];
        strcpy_s(m_title, length, title);
        return *this;
    }

    Position& setResposibility(Responsibility responsibility) { m_responsibility = responsibility; return *this; }
    Position& setSalary(float salary) { m_salary = salary; return *this; }

    static Position Interactive(std::istream& is, std::ostream& os)
    {
        char title[MAX_NAME];
        os << "\tEnter title: ";
        is.getline(title, MAX_NAME);
        int resp;

        do
        {
            if (!is)
            {
                is.clear();
                is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            os << "\tEnter responsibility (0-None, 1-Worker, 2-Manager, 3-Employer): ";
            is >> resp;
        } while (resp < 0 || resp > 3 || !is);

        float salary;
        do
        {
            if (!is)
            {
                is.clear();
                is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            os << "\tEnter salary: ";
            is >> salary;
        } while (!is);

        return Position(title, static_cast<Responsibility>(resp), salary);
    }

    // Destructor
    virtual ~Position()
    {
        TRACE_ME;
        delete[] m_title;
    }
};