#pragma once
#include "Date.h"

class Person
{
    size_t MAX_NAME = 250;

    char* m_name;
    char* m_surName;

    Date m_birth;
public:
    // Constructors
    Person() :
        m_name(nullptr), m_surName(nullptr)
    { }

    Person(const char* name, const char* surName, const Date& birth) :
        m_birth(birth)
    {
        size_t length = strnlen_s(name, MAX_NAME) + 1;
        m_name = new char[length];
        strcpy_s(m_name, length, name);

        length = strnlen_s(surName, MAX_NAME) + 1;
        m_surName = new char[length];
        strcpy_s(m_surName, length, surName);
    }

    Person(const Person& other) :
        m_birth(other.m_birth)
    {
        size_t length = strnlen_s(other.m_name, MAX_NAME) + 1;
        m_name = new char[length];
        strcpy_s(m_name, length, other.m_name);

        length = strnlen_s(other.m_surName, MAX_NAME) + 1;
        m_surName = new char[length];
        strcpy_s(m_surName, length, other.m_surName);
    }

    Person(Person&& other) :
        m_name(other.m_name), m_surName(other.m_surName),
        m_birth(other.m_birth)
    {
        other.m_name = nullptr;
        other.m_surName = nullptr;
    }

    // Assignment operator
    Person& operator=(const Person& other)
    {
        if (this == &other)
            return *this;

        m_birth = other.m_birth;

        delete[] m_name;
        if (other.m_name == nullptr)
            m_name = nullptr;
        else
        {
            size_t length = strnlen_s(other.m_name, MAX_NAME) + 1;
            m_name = new char[length];
            strcpy_s(m_name, length, other.m_name);
        }

        delete[] m_surName;
        if (other.m_surName == nullptr)
            m_surName = nullptr;
        else
        {
            size_t length = strnlen_s(other.m_surName, MAX_NAME) + 1;
            m_surName = new char[length];
            strcpy_s(m_surName, length, other.m_surName);
        }

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
        size_t length = strnlen_s(name, MAX_NAME) + 1;
        m_name = new char[length];
        strcpy_s(m_name, length, name);

        return *this;
    }

    Person& setSurName(const char* surName)
    {
        delete m_surName;
        size_t length = strnlen_s(surName, MAX_NAME) + 1;
        m_surName = new char[length];
        strcpy_s(m_surName, length, surName);

        return *this;
    }

    Person& setBirth(const Date& birth) { m_birth = birth; return *this; }

    // Destructor
    virtual ~Person()
    {
        delete[] m_name;
        delete[] m_surName;
    }
};