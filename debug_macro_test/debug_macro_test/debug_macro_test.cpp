// debug_macro_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	DEBUGPRINT("argc = %d", argc);
	DEBUGPRINT("Hello world.");
	DEBUGPRINT( "%s %s%c", "Hello", "world", '.' );
	DEBUGPRINT( "%s.", "Hello world" );	
	DEBUGPRINT("%s", wstring_to_string( _T("не много русской кодировка.") ).c_str() );
	DEBUGPRINT("|%s|", wstring_to_string(argv[0]).c_str());

	return 0;
}

