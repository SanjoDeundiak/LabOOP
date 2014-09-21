#ifndef _DEBUG
    #define TRACE_ME
#else
    #include <fstream>
    extern std::ofstream TRACE_STREAM; 
    #define TRACE_ME TRACE_STREAM << __FUNCTION__ << std::endl;
#endif