#pragma once
#include "Employee.h"
#include <ostream>
#include <new.h>

class Organization
{
    size_t MAX_NAME = 250;

    char* m_name;
    size_t m_size;
    Employee* m_employees;
    size_t m_counter;

    void reallocate(const Employee* source, size_t newSize)
    {
        Employee* newArr = (Employee*)(malloc(newSize * sizeof(Employee)));

        memcpy_s(newArr, newSize * sizeof(Employee), source, m_size * sizeof(Employee));

        free(m_employees);
        m_employees = newArr;
        m_size = newSize;
    }

    float totalSalary() const
    {
        float res = 0;

        for (size_t i = 0; i < m_counter; i++)
            res += m_employees[i].GetPosition().GetSalary();

        return res;
    }
public:
    friend std::ostream& operator<<(std::ostream& os, const Organization& organization); // For output

    // Constructors
    Organization() :
        m_name(nullptr), m_size(10), m_counter(0),
        m_employees((Employee*)(malloc(m_size * sizeof(Employee))))
    { }

    Organization(const Organization& other) :
        m_size(other.m_size), m_counter(other.m_counter)
    {
        m_employees = (Employee*)(malloc(m_size * sizeof(Employee)));

        for (size_t i = 0; i < m_counter; i++)
            new(m_employees + i) Employee(other.m_employees[i]);
    }

    Organization(const char* name, const Employee* employees, size_t counter)
    {
        m_size = (employees) ? 2 * counter : 10;
        m_size = (m_size > 10) ? m_size : 10;
        m_employees = (Employee*)(malloc(m_size * sizeof(Employee)));

        m_counter = (employees) ? counter : 0;

        if (m_counter)
        {
            for (size_t i = 0; i < m_counter; i++)
                new(m_employees + i) Employee(employees[i]);
        }

        if (!name)
        {
            m_name = nullptr;
            return;
        }

        size_t length = strnlen_s(name, MAX_NAME) + 1;
        m_name = new char[length];
        strcpy_s(m_name, length, name);
    }

    // Assignment operator
    Organization& operator=(const Organization& other)
    {
        for (size_t i = 0; i < m_counter; i++)
            m_employees[i].~Employee();
        free(m_employees);
        m_counter = other.m_counter;
        m_size = other.m_size;
        m_employees = (Employee*)(malloc(m_size * sizeof(Employee)));
        for (size_t i = 0; i < m_counter; i++)
            new(m_employees + i) Employee(other.m_employees[i]);

        return *this;
    }

    void AddEmployee(const Employee& employee)
    {
        if (m_counter == m_size)
            reallocate(m_employees, 2 * m_size);

        m_employees[m_counter++] = employee;
    }

    // Getters
    const char* GetName() const { return m_name; }
    const Employee* const GetIEmployee(size_t i) const { return (i < m_counter) ? m_employees + i : nullptr; }
    size_t GetSize() const { return m_counter; }

    // Setters
    Organization& SetName(const char* name)
    {
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

    Organization& SetIEmployee(const Employee& employee, size_t i)
    {
        m_employees[i] = (i < m_counter) ? employee : m_employees[i];
        return *this;
    }

    // Output
    std::ostream& Brief(std::ostream& os)
    {
        os << "Organization: " << m_name << std::endl
            << "Total salary: " << totalSalary() << std::endl;

        return os;
    }

    // Destructor
    virtual ~Organization()
    {
        for (size_t i = 0; i < m_counter; i++)
            m_employees[i].~Employee();
        free(m_employees);
    }
};

std::ostream& operator<<(std::ostream& os, const Organization& organization)
{
    os << "Organization: " << organization.m_name << std::endl
        << organization.m_counter << " employess :" << std::endl;

    for (size_t i = 0; i < organization.m_counter; i++)
        os << '[' << i << "]: " << *organization.GetIEmployee(i) << std::endl;

    return os;
}