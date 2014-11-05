// debug_macro_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	DEBUGPRINT( ("argc = %d\n", argc) );
	DEBUGPRINT( ("blah\n") );
	DEBUGPRINT( ("%ws\n", argv[0]) );
	DEBUGPRINT( ((char *)argv[0]) );
	return 0;
}

