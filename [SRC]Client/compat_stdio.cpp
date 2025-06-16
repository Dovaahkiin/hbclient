#ifdef _MSC_VER
#include <stdio.h>

// Provide the deprecated __iob symbol used by older libraries
#if _MSC_VER >= 1400
extern "C" FILE* __imp___iob_func = __acrt_iob_func(0);
#else
extern "C" FILE _iob[] = { *stdin, *stdout, *stderr };
extern "C" FILE* __imp___iob = _iob;
#endif

// Map legacy import variables for common stdio routines
extern "C" int (__cdecl* __imp__printf)(const char*, ...)   = &printf;
extern "C" int (__cdecl* __imp__fprintf)(FILE*, const char*, ...) = &fprintf;
extern "C" int (__cdecl* __imp__sscanf)(const char*, const char*, ...) = &sscanf;
#endif
