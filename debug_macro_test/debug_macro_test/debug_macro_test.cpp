// debug_macro_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{	
	DEBUGPRINT( ("argc = %d\n", argc) );
	DEBUGPRINT( ("Hello world.\n") );

	DEBUGPRINT( ("%s %s\n", "Hello", "world") );
	DEBUGPRINT( ("%s\n", "Hello world") );
	return 0;
}

