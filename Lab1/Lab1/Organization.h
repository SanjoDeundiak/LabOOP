#pragma once
#include "Employee.h"
#include <ostream>
#include <new.h>

class Organization
{
    // Constants
    static const size_t MAX_NAME = 250;
    static const char* DEFAULT_NAME;

    // Members
    char* m_name;
    size_t m_size;
    Employee* m_employees;
    size_t m_counter;

    void reallocate(const Employee* source, size_t newSize);
public:
    friend std::ostream& operator<<(std::ostream& os, const Organization& organization); // For output

    // Constructors
    Organization();
    Organization(const Organization& other);
    Organization(Organization&& other);
    Organization(const char* name, const Employee* employees, size_t counter);

    // Assignment operators
    Organization& operator=(const Organization& other);
    Organization& operator=(Organization&& other);

    void AddEmployee(const Employee& employee);
    void AddEmployee(Employee&& employee);

    // Getters
    const char* GetName() const { return m_name; }
    const Employee* const GetIEmployee(size_t i) const { return (i < m_counter) ? m_employees + i : nullptr; }
    size_t GetSize() const { return m_counter; }

    // Setters
    Organization& SetName(const char* name);
    Organization& SetIEmployee(const Employee& employee, size_t i);

    // Output
    std::ostream& Brief(std::ostream& os) const;

    static Organization Interactive(std::istream& is, std::ostream& os);

    // Destructor
    virtual ~Organization();
};