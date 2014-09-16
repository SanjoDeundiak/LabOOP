#pragma once
#include <string.h>

enum class Responsibility
{
    None,
    Worker,
    Manager,
    Employer
};

class Position
{
    size_t MAX_NAME = 250;

    char* m_title;
    Responsibility m_responsibility;
    float m_salary;

public:
    // Constructors
    Position() :
        m_title(nullptr), m_salary(0),
        m_responsibility(Responsibility::None)
    { }

    Position(const char* title, Responsibility responsibility, float salary) :
        m_responsibility(responsibility), m_salary(salary)
    {
        if (title == nullptr)
            m_title = nullptr;
        else
        {
            size_t length = strnlen_s(title, MAX_NAME) + 1;
            m_title = new char[length];
            strcpy_s(m_title, length, title);
        }
    }

    Position(const Position& other) :
        m_responsibility(other.m_responsibility), m_salary(other.m_salary)
    {
        delete[] m_title;
        if (other.m_title == nullptr)
            m_title = nullptr;
        else
        {
            size_t length = strnlen_s(other.m_title, MAX_NAME) + 1;
            m_title = new char[length];
            strcpy_s(m_title, length, other.m_title);
        }
    }

    Position(Position&& other) :
        m_responsibility(other.m_responsibility), m_salary(other.m_salary)
    {
        m_title = other.m_title;
        other.m_title = nullptr;
    }

    // Assignment operator
    Position& operator=(const Position& other)
    {
        if (this == &other)
            return *this;

        m_salary = other.m_salary;
        m_responsibility = other.m_responsibility;

        delete[] m_title;
        if (other.m_title == nullptr)
            m_title = nullptr;
        else
        {
            size_t length = strnlen_s(other.m_title, MAX_NAME) + 1;
            m_title = new char[length];
            strcpy_s(m_title, length, other.m_title);
        }

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
        if (title == nullptr)
            m_title = nullptr;
        {
            size_t length = strnlen_s(title, MAX_NAME) + 1;
            m_title = new char[length];
            strcpy_s(m_title, length, title);
        }

        return *this;
    }

    Position& setResposibility(Responsibility responsibility) { m_responsibility = responsibility; return *this; }
    Position& setSalary(float salary) { m_salary = salary; return *this; }

    // Destructor
    virtual ~Position()
    {
        delete[] m_title;
    }
};