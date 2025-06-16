#ifdef _MSC_VER
#include <stdio.h>

// Provide the deprecated __iob symbol used by older libraries
extern "C" FILE _iob[] = { *stdin, *stdout, *stderr };
extern "C" FILE* __imp___iob = _iob;

// Map legacy import variables for common stdio routines
extern "C" int (__cdecl* __imp__printf)(const char*, ...)   = &printf;
extern "C" int (__cdecl* __imp__fprintf)(FILE*, const char*, ...) = &fprintf;
extern "C" int (__cdecl* __imp__sscanf)(const char*, const char*, ...) = &sscanf;
#endif
