#include "Organization.h"
#include "Test.h"
#include "Trace.h"
#include <iostream>

std::ofstream TRACE_STREAM("__TRACE.txt");

int main()
{
    TRACE_ME
    TestOrganization::Test(std::cin, std::cout);

    std::cin.get();
}