#include "Date.h"
#include "Employee.h"
#include "Person.h"
#include "Position.h"
#include "Organization.h"
#include <iostream>
#include <iomanip>

// Forward decl
std::ostream &operator<<(std::ostream &os, const Date& date);
std::ostream& operator<<(std::ostream& os, const Person& person);
std::ostream& operator<<(std::ostream& os, const Responsibility& responsibility);
std::ostream& operator<<(std::ostream& os, const Employee& employee);
std::ostream& operator<<(std::ostream& os, const Position& position);
std::ostream& operator<<(std::ostream& os, const Organization& organization);

std::ostream &operator<<(std::ostream &os, const Date& date)
{
    using namespace std;
    char temp = os.fill('0');
    os << setw(2) << date.GetDay() << '.'
        << setw(2) << date.GetMonth() << '.'
        << date.GetYear();

    os.fill(temp);
    return os.flush();
}

std::ostream& operator<<(std::ostream& os, const Person& person)
{
    os << "\t\tName: " <<((person.GetName()) ? person.GetName() : Person::DEFAULT_NAME) << ' '
        << ((person.GetSurName()) ? person.GetSurName() : Person::DEFAULT_SURNAME) << '\n'
        << "\t\tBirth: " << person.GetBirth();

    return os.flush();
}

std::ostream& operator<<(std::ostream& os, const Responsibility& responsibility)
{
    switch (responsibility)
    {
    case Responsibility::None: os << "No responsibilities"; break;
    case Responsibility::Worker: os << "Worker"; break;
    case Responsibility::Manager: os << "Manager"; break;
    case Responsibility::Employer: os << "Employer"; break;
    }

    return os.flush();
}

std::ostream& operator<<(std::ostream& os, const Employee& employee)
{
    os << "\tPerson:\n" << employee.GetPerson() << '\n'
        << "\tPosition:\n" << employee.GetPosition() << '\n'
        << "\tHire date:\n\t\t" << employee.GetHireDate();

    return os.flush();
}

std::ostream& operator<<(std::ostream& os, const Position& position)
{
    os << "\t\t" << "Title: " << ((position.GetTitle()) ? position.GetTitle() : Position::DEFAULT_TITLE) << '\n'
        << "\t\tResponsibility: " << position.GetResponsibility() << '\n'
        << "\t\tSalary: $" << position.GetSalary();

    return os.flush();
}

std::ostream& operator<<(std::ostream& os, const Organization& organization)
{
    os << "Organization: " << ((organization.GetName()) ? organization.GetName() : Organization::DEFAULT_NAME) << std::endl
        << organization.GetSize() << " employee(s)" << std::endl;

    for (size_t i = 0; i < organization.m_counter; i++)
        os << '[' << i+1 << "]: " << *organization.GetIEmployee(i) << std::endl;

    return os;
}

std::ostream& Organization::Brief(std::ostream& os) const
{
    float res = 0;

    for (size_t i = 0; i < m_counter; i++)
        res += m_employees[i].GetPosition().GetSalary();

    os << "Organization: " << ((m_name) ? m_name : DEFAULT_NAME) << std::endl
        << "Total salary: " << res << std::endl;

    return os;
}