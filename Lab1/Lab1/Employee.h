#pragma once
#include "Position.h"
#include "Date.h"
#include "Person.h"
#include <ostream>

class Employee
{
    Position m_position;
    Person m_person;
    Date m_hireDate;

public:
    friend std::ostream& operator<<(std::ostream& os, const Employee& employee); // For output

    // Constructors
    Employee() = default;

    Employee(const Position& position, const Person& person, const Date& hireDate) :
        m_position(position), m_person(person),
        m_hireDate(hireDate)
    { }

    Employee(const Employee&) = default;

    Employee(Employee&& other) :
        m_position(std::move(other.m_position)), m_person(std::move(other.m_person)),
        m_hireDate(std::move(other.m_hireDate))
    {
        TRACE_ME
    }

    // Asignment operators
    Employee& operator=(const Employee&) = default;

    Employee& operator=(Employee&& other)
    {
        TRACE_ME
        m_position = std::move(other.m_position);
        m_person = std::move(other.m_person);
        m_hireDate = std::move(other.m_hireDate);
    }

    // Getters
    const Position& GetPosition() const { return m_position; }
    const Person& GetPerson() const { return m_person; }
    const Date& GetHireDate() const { return m_hireDate; }

    // Setters
    Employee& SetPosition(const Position& position) { m_position = position; return *this; }
    Employee& SetPerson(const Person& person) { m_person = person; return *this; }
    Employee& SetHireDate(const Date& hireDate) { m_hireDate = hireDate; return *this; }

    static Employee Interactive(std::istream& is, std::ostream& os)
    {
        os << "Position:\n";
        Position pos = Position::Interactive(is, os);
        os << "Person:\n";
        Person pers = Person::Interactive(is, os);
        os << "Enter hire date in format dd mm yyyy: ";
        return Employee(pos, pers, Date::Interactive(is));
    }

    // Destructor
    virtual ~Employee() { }
};