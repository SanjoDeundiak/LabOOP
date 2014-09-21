#include "Organization.h"
#include "Test.h"
#include "Trace.h"
#include <iostream>

std::ofstream TRACE_STREAM("__TRACE.txt");

int main()
{
    TRACE_ME
    TestOrganization::Test(std::cin, std::cout);

    if (!std::cin || !std::cout)
    {
        std::cout.clear();
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Something went wrong" << std::endl;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}