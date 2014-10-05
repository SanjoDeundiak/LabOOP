#ifndef _DEBUG
    #define TRACE_ME
    #define TRACE_STREAM_INIT(filePath)
#else
    #include <fstream>
    extern std::ofstream TRACE_STREAM; 
    #define TRACE_ME TRACE_STREAM << __FUNCTION__ << std::endl
    #define TRACE_COMMENT(str) TRACE_STREAM << "---" << str << "---" << std::endl
    #define TRACE_STREAM_INIT(filePath) std::ofstream TRACE_STREAM(filePath);
#endif