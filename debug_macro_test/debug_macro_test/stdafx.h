// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <string>

#include <stdio.h>
#include <tchar.h>

extern std::string dbu_prefix(char * file, int line);
extern std::string dbu_format(char * format, ...);

#define DEBUGPRINT( ... ) printf( "%s %s\n", dbu_prefix(__FILE__, __LINE__).c_str(), dbu_format( __VA_ARGS__ ).c_str() )
//...
// DEBUGPRINT("hey, x=%d\n", x);

// TODO: reference additional headers your program requires here
