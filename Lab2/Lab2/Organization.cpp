#include "Organization.h"
#include "Trace.h"

// Constructors
Organization::Organization() :
    m_name(nullptr), m_size(10), m_counter(0),
    m_employees((Employee*)(malloc(m_size * sizeof(Employee))))
{ }

Organization::Organization(const char* name, const Employee* employees, size_t counter)
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

Organization::Organization(const Organization& other) :
    m_size(other.m_size), m_counter(other.m_counter)
{
    m_employees = (Employee*)(malloc(m_size * sizeof(Employee)));

    for (size_t i = 0; i < m_counter; i++)
        new(m_employees + i) Employee(other.m_employees[i]);

    if (!other.m_name)
    {
        m_name = nullptr;
        return;
    }

    size_t length = strnlen_s(other.m_name, MAX_NAME) + 1;
    m_name = new char[length];
    strcpy_s(m_name, length, other.m_name);
}

Organization::Organization(Organization&& other) :
    m_size(other.m_size), m_counter(other.m_counter),
    m_employees(other.m_employees), m_name(other.m_name)
{
    other.m_counter = 0;
    other.m_employees = nullptr;
    other.m_name = nullptr;
}

// Setters
Organization& Organization::SetName(const char* name)
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

Organization& Organization::SetIEmployee(const Employee& employee, size_t i)
{
    if (i >= m_counter || &m_employees[i] == &employee)
        return *this;

    m_employees[i].~Employee();
    m_employees[i] = employee;
    return *this;
}

void Organization::AddEmployee(const Employee& employee)
{
    if (m_counter == m_size)
        reallocate(m_employees, 2 * m_size);

    new(m_employees + m_counter++) Employee(employee);
}

void Organization::AddEmployee(Employee&& employee)
{
    if (m_counter == m_size)
        reallocate(m_employees, 2 * m_size);

    new(m_employees + m_counter++) Employee(std::move(employee));
}

// Assignment operators
Organization& Organization::operator=(const Organization& other)
{
    if (&other == this)
        return *this;

    for (size_t i = 0; i < m_counter; i++)
        m_employees[i].~Employee();
    free(m_employees);
    m_counter = other.m_counter;
    m_size = other.m_size;
    m_employees = (Employee*)(malloc(m_size * sizeof(Employee)));
    for (size_t i = 0; i < m_counter; i++)
        new(m_employees + i) Employee(other.m_employees[i]);

    delete[] m_name;
    if (!other.m_name)
    {
        m_name = nullptr;
        return *this;
    }

    size_t length = strnlen_s(other.m_name, MAX_NAME) + 1;
    m_name = new char[length];
    strcpy_s(m_name, length, other.m_name);

    return *this;
}

Organization& Organization::operator=(Organization&& other)
{
    m_employees = other.m_employees;
    m_size = m_size;
    m_counter = other.m_counter;
    m_name = other.m_name;

    other.m_name = nullptr;
    other.m_employees = nullptr;
    other.m_counter = 0;
    other.m_size = 0;

    return *this;
}

// Destructor
Organization::~Organization()
{
    for (size_t i = 0; i < m_counter; i++)
        m_employees[i].~Employee();
    free(m_employees);

    delete[] m_name;
}

// Additional functions
void Organization::reallocate(const Employee* source, size_t newSize)
{
    Employee* newArr = (Employee*)(malloc(newSize * sizeof(Employee)));

    memcpy_s(newArr, newSize * sizeof(Employee), source, m_size * sizeof(Employee));

    free(m_employees);
    m_employees = newArr;
    m_size = newSize;
}

Organization Organization::Interactive(std::istream& is, std::ostream& os)
{
    char name[MAX_NAME];
    os << "Enter name: ";
    is.getline(name, MAX_NAME);
    os << "Enter number of employees: ";
    size_t number;

    is >> number;
    while (!is)
    {
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        is >> number;
    }

    Organization org(name, nullptr, 0);
    for (size_t i = 0; i < number; i++)
    {
        is.ignore();
        os << "Employee #" << i + 1 << std::endl;
        org.AddEmployee(Employee::Interactive(is, os));
    }
    return org;
}