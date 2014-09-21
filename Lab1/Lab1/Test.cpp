#include "Organization.h"

namespace TestOrganization
{
    void Test(std::istream& is, std::ostream &os)
    {
        os << __FUNCTION__ << std::endl;

        // Default constructor
        os << "DEFAULT CONSTRUCTOR TEST" << std::endl;
        Organization org1;
        os << org1 << std::endl;
        org1.Brief(os) << std::endl;

        os << "SETTING NAME. ADDING EMPLOYEE" << std::endl;
        org1.SetName("Microsoft");
        Date hireDate(2014, 8, 25), birthDate(1995, 1, 20);
        Person person("Sanjo", "Deundiak", birthDate);
        Position position("Head officer", Responsibility::Manager, 5000.f);
        Employee employee(position, person, hireDate);
        org1.AddEmployee(employee);
        os << "__FULL__" << std::endl;
        os << org1 << std::endl;
        os << "__BRIEF__" << std::endl;
        org1.Brief(os) << std::endl;

        os << "ADDING 2 MORE EMPLOYEES AND TESTING COPY CONSTRUCTOR" << std::endl;

        org1.AddEmployee(Employee(Position("Assistant", Responsibility::Worker, 1000), Person("Mark", "Zuckerberg", Date(1984, 14, 5)), Date()));
        org1.AddEmployee(Employee(Position("Designer", Responsibility::Worker, 2500), Person("Artemii", "Lebedev", Date(1975, 13, 2)), Date()));

        Organization org2(org1);
        os << "__FULL__" << std::endl;
        os << org2 << std::endl;
        os << "__BRIEF__" << std::endl;
        org2.Brief(os) << std::endl;

        os << "GETTING ARRAY AND TESTING CONSTRUCTOR WITH ARGUMENTS" << std::endl;

        Employee* employees = new Employee[org2.GetSize()];

        for (size_t i = 0; i < org2.GetSize(); i++)
            employees[i] = *org2.GetIEmployee(i);
        Organization org3 = Organization("Dynamic Systems", employees, org1.GetSize());
        os << "__FULL__" << std::endl;
        os << org3 << std::endl;
        os << "__BRIEF__" << std::endl;
        org3.Brief(os) << std::endl;

        delete[] employees;
    }
}