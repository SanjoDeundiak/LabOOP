#include "Employee.h"

int main()
{
    Position pos("Head officer", Responsibility::Manager, 5000);
    Person pers("Sanjo", "Deundiak", Date(1995, 1, 20));
    Employee emp(pos, pers, Date());

    Employee emp2(Employee());
}