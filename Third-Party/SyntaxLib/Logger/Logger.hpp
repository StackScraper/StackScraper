#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include <string>
#include <logger_export.h>

class LOGGER_EXPORT CLogger
{

public:
    
    void Log(const char* msg);

};


#endif // __LOGGER_HPP__