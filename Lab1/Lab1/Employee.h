#pragma once
#include "Position.h"
#include "Date.h"
#include "Person.h"

class Employee
{
    Position m_position;
    Person m_person;
    Date m_hireDate;

public:
    Employee() :
        m_position(), m_person(),
        m_hireDate()
    { }

    Employee(const Position& position, const Person& person, const Date& hireDate) :
        m_position(position), m_person(person),
        m_hireDate(hireDate)
    { }

    Employee(const Employee& other) :
        m_position(other.m_position), m_person(other.m_person),
        m_hireDate(other.m_hireDate)
    { }

    Employee(Employee&& other) :
        m_position(other.m_position), m_person(other.m_person),
        m_hireDate(other.m_hireDate)
    { }
};