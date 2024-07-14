#include "SyntX.hpp"

__attribute__((visibility("default")))
void CLogger::Log(const char* msg)
{
    printf("Logged: %s", msg);
}