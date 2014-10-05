#pragma once
#include "Date.h"
#include <string>
#include <ostream>
#include "Trace.h"

class Person
{
    // Constants
    static const size_t MAX_NAME = 250;
    static const char* DEFAULT_NAME;
    static const char* DEFAULT_SURNAME;

    char* m_name;
    char* m_surName;

    Date m_birth;
public:
    friend std::ostream& operator<<(std::ostream& os, const Person& person); // For output

    // Constructors
    Person() :
        m_name(nullptr), m_surName(nullptr)
    {
        TRACE_ME;
    }

    Person(const char* name, const char* surName, const Date& birth) :
        m_birth(birth)
    {
        TRACE_ME;
        if (!name)
            m_name = nullptr;
        else
        {
            size_t length = strnlen_s(name, MAX_NAME) + 1;
            m_name = new char[length];
            strcpy_s(m_name, length, name);
        }

        if (!surName)
            m_surName = nullptr;
        else
        {
            size_t length = strnlen_s(surName, MAX_NAME) + 1;
            m_surName = new char[length];
            strcpy_s(m_surName, length, surName);
        }
    }

    Person(const Person& other) :
        m_birth(other.m_birth)
    {
        TRACE_ME;
        if (!other.m_name)
            m_name = nullptr;
        else
        {
            size_t length = strnlen_s(other.m_name, MAX_NAME) + 1;
            m_name = new char[length];
            strcpy_s(m_name, length, other.m_name);
        }

        if (!other.m_surName)
            m_surName = nullptr;
        else
        {
            size_t length = strnlen_s(other.m_surName, MAX_NAME) + 1;
            m_surName = new char[length];
            strcpy_s(m_surName, length, other.m_surName);
        }
    }

    Person(Person&& other) :
        m_name(other.m_name), m_surName(other.m_surName),
        m_birth(other.m_birth)
    {
        TRACE_ME;
        other.m_name = nullptr;
        other.m_surName = nullptr;
    }

    // Assignment operators
    Person& operator=(const Person& other)
    {
        TRACE_ME;
        if (this == &other)
            return *this;

        m_birth = other.m_birth;

        delete[] m_name;
        if (!other.m_name)
            m_name = nullptr;
        else
        {
            size_t length = strnlen_s(other.m_name, MAX_NAME) + 1;
            m_name = new char[length];
            strcpy_s(m_name, length, other.m_name);
        }

        delete[] m_surName;
        if (!other.m_surName)
            m_surName = nullptr;
        else
        {
            size_t length = strnlen_s(other.m_surName, MAX_NAME) + 1;
            m_surName = new char[length];
            strcpy_s(m_surName, length, other.m_surName);
        }

        return *this;
    }

    Person& operator=(Person&& other)
    {
        TRACE_ME;
        m_birth = other.m_birth;

        delete[] m_name;
        m_name = other.m_name;
        other.m_name = nullptr;

        delete[] m_surName;
        m_surName = other.m_surName;
        other.m_surName = nullptr;

        return *this;
    }

    // Getters
    const char* GetName() const    { return m_name;    }
    const char* GetSurName() const { return m_surName; }
    const Date& GetBirth() const   { return m_birth;   }

    // Setters
    Person& setName(const char* name)
    {
        delete m_name;
        if (!name)
        {
            m_name = nullptr;
            return *this;
        }

        size_t length = strnlen_s(name, MAX_NAME) + 1;
        m_name = new char[length];
        strcpy_s(m_name, length, name);

        return *this;
    }

    Person& setSurName(const char* surName)
    {
        delete m_surName;
        if (!surName)
        {
            m_surName = nullptr;
            return *this;
        }

        size_t length = strnlen_s(surName, MAX_NAME) + 1;
        m_surName = new char[length];
        strcpy_s(m_surName, length, surName);

        return *this;
    }

    Person& setBirth(const Date& birth) { m_birth = birth; return *this; }

    static Person Interactive(std::istream& is, std::ostream& os)
    {
        is.ignore();
        char name[MAX_NAME], surName[MAX_NAME];
        os << "\tEnter name: ";
        is.getline(name, MAX_NAME);

        os << "\tEnter surname: ";
        is.getline(surName, MAX_NAME);

        os << "\tEnter date of birth in format dd mm yyyy: ";

        return Person(name, surName, Date::Interactive(is));
    }

    // Destructor
    virtual ~Person()
    {
        TRACE_ME;
        delete[] m_name;
        delete[] m_surName;
    }
};