#include "stdafx.h"

#include <string>

#include <Windows.h>

std::string wstring_to_string(const std::wstring &ws)
{		
	const unsigned int cp = 20866/*CP_ACP*/;
	int len = WideCharToMultiByte(cp, // ANSI Code Page
		0, // No special handling of unmapped chars
		ws.c_str(), // wide-character string to be converted
		ws.size(),
		NULL, 0, // No output buffer since we are calculating length
		NULL, NULL); // Unrepresented char replacement - Use Default

	char *buf = (char *)_alloca(len+1); // nUserNameLen includes the NULL character 
	// +1 for '\0'
	WideCharToMultiByte(cp, // ANSI Code Page
		0, // No special handling of unmapped chars
		ws.c_str(), // wide-character string to be converted
		ws.size(),
		buf,
		len,
		NULL, NULL); // Unrepresented char replacement - Use Default
	buf[len] = '\0';
	return std::string(buf);
}