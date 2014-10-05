#include "Organization.h"

namespace TestOrganization
{
    void Test(std::istream& is, std::ostream &os)
    {
        TRACE_ME;

        TRACE_COMMENT("Creating date");
        Date date;
        os << date << std::endl;

        TRACE_COMMENT("Creating person");
        Person person("Oleksandr", "Deundiak", Date(20, 1, 1995));
        os << person << std::endl;
        TRACE_COMMENT("Creating position");
        Position position("Head officer", Responsibility::Manager, 5000);
        os << position << std::endl;
        TRACE_COMMENT("Creating employee");
        Employee employee(position, person, Date());
        os << employee << std::endl;
        TRACE_COMMENT("END");
    }
}