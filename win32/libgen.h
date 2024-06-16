#ifndef libgen_h__
#define libgen_h__

#include <windows.h>

LPCSTR basename(LPCSTR filename);
int asprintf(char **strp, const char *fmt, ...);

#endif // libgen_h__
