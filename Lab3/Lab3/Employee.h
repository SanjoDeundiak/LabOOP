#pragma once
#include "Position.h"
#include "Date.h"
#include "Person.h"
#include <ostream>

class Employee : public Person, public Position
{
    Date m_hireDate;

public:
    friend std::ostream& operator<<(std::ostream& os, const Employee& employee); // For output

    void Brief(std::ostream& os) const;

    // Constructors
    Employee() : Person(), Position(),
        m_hireDate()
    {
        TRACE_ME;
    }

    Employee(const Position& position, const Person& person, const Date& hireDate) :
        Position(position), Person(person),
        m_hireDate(hireDate)
    {
        TRACE_ME;
    }

    Employee(const Employee& other) :
        Person(other), Position(other),
        m_hireDate(other.m_hireDate)
    {
        TRACE_ME;
    }

    Employee(Employee&& other) :
        Position(std::move(other)), Person(std::move(other)),
        m_hireDate(std::move(other.m_hireDate))
    {
        TRACE_ME;
    }

    // Asignment operators
    Employee& operator=(const Employee& other)
    {
        TRACE_ME;
        if (this == &other)
            return *this;
        Person::operator=(other);
        Position::operator=(other);
        m_hireDate = other.m_hireDate;

        return *this;
    }

    Employee& operator=(Employee&& other)
    {
        TRACE_ME;
        Position::operator=(std::move(other));
        Person::operator=(std::move(other));
        m_hireDate = std::move(other.m_hireDate);

        return *this;
    }

    // Getters
    const Position& GetPosition() const { return *this; }
    const Person& GetPerson() const { return *this; }
    const Date& GetHireDate() const { return m_hireDate; }

    // Setters
    Employee& SetPosition(const Position& position) { Position::operator=(position); return *this; }
    Employee& SetPerson(const Person& person) { Person::operator=(person); return *this; }
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
    virtual ~Employee()
    {
        TRACE_ME;
    }
};