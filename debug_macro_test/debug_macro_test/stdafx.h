// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

// debugging macros so we can pin down message origin at a glance
#define WHERESTR  "[file %s, line %d]: "
#define WHEREARG  __FILE__, __LINE__
#define DEBUGPRINT2(...)		fprintf(stdout, __VA_ARGS__)
#define DEBUGPRINT( x ) DEBUGPRINT2 x
//...
// DEBUGPRINT("hey, x=%d\n", x);

// TODO: reference additional headers your program requires here
