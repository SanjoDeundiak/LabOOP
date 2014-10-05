#include "Date.h"
#include "Person.h"
#include "Position.h"


std::istream& operator>>(std::istream& is, Person& person)
{
    is.ignore();
    char name[Person::MAX_NAME], surName[Person::MAX_NAME];
    Date date;
    is.getline(name, Person::MAX_NAME);
    person.setName(name);
    is.getline(surName, Person::MAX_NAME);
    person.setSurName(name);
    is >> person.m_birth;

    return is;
}

std::istream& operator>>(std::istream& is, Position& position)
{
    char title[Position::MAX_NAME];
    is.getline(title, Position::MAX_NAME);
    position.setTitle(title);

    int resp;
    do
    {
        if (!is)
        {
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        is >> resp;
    } while (resp < 0 || resp > 3 || !is);
    position.setResposibility(static_cast<Responsibility>(resp));

    float salary;
    do
    {
        if (!is)
        {
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        is >> salary;
    } while (!is);
    position.setSalary(salary);

    return is;
}

std::istream &operator>>(std::istream &is, Date& date)
{
    return is >> date.m_day >> date.m_month >> date.m_year;
}