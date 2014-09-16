#pragma once
#include "Employee.h"
#include <iostream>
#include <new.h>

class Organization
{
    char* m_name;
    size_t m_size;
    Employee* m_employees;
    size_t m_counter;

    void reallocate()
    {
        Employee* newArr = (Employee*)(malloc(2 * m_size * sizeof(Employee)));

        memcpy_s(newArr, 2 * m_size * sizeof(Employee), m_employees, m_size * sizeof(Employee));

        free(m_employees);
        m_employees = newArr;
        m_size *= 2;
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

    void AddEmployee(const Employee& employee)
    {
        if (m_counter == m_size)
            reallocate();

        m_employees[m_counter++] = employee;
    }
};

std::ostream& operator<<(std::ostream& os, const Organization& organization)
{
    os << setw(20) << std::endl;
}