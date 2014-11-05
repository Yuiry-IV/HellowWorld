// stdafx.cpp : source file that includes just the standard includes
// debug_macro_test.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <malloc.h>

#include <sstream>
#include <iomanip>

std::string dbu_prefix(char * file, int line)
{
	std::string sf(file?file:"null");

	std::stringstream s;
	s << '[';
	if (sf.rfind('\\') != -1)
	{
		s << "<";
		s << sf.erase(0, sf.rfind('\\') + 1);
	}
	else
	{
		s << sf;
	}
	s << ':';
	s <<std::setw(4)<<std::setfill('0')<< line;
	s << ']';
	return s.str();
}

std::string dbu_format(char * format, ...)
{
	va_list args;
	int     len;
	char    *buffer;

	// retrieve the variable arguments
	va_start(args, format);

	len = _vscprintf(format, args) // _vscprintf doesn't count
		+ 1; // terminating '\0'

	buffer = (char*)_alloca(len * sizeof(char));

	vsprintf(buffer, format, args); // C4996
	// Note: vsprintf is deprecated; consider using vsprintf_s instead
	//puts(buffer);

	return std::string(buffer);
	//free(buffer);
}