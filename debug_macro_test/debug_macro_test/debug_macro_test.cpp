// debug_macro_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

template<typename T> void my_swap(T &l, T &r)
{
	T temp(l);
	l = r;
	r = temp;
}
template<typename T> void my_sort(T b, T e)
{
	for (T i = b; i != e; ++i)
	{
		T min_i = i;
		for (T j = i; j != e; ++j)
		{
			if (*min_i > *j)
			{
				min_i = j;
			}
		}
		my_swap(*min_i, *i);
	}
}

//typedef unsigned int user_type;
typedef std::string user_type;

const std::string _char_set = "\
0123456789abcdefghjiklmnoqrstuvwxyzABCDEFGHJIKLMNOQRSTUVWXYZ~`-_=*^$#@!\
";

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<user_type> v(25);
	std::srand(std::time(0));
	std::rand();
	std::rand();
	std::rand();
	std::rand();

	//std::generate(v.begin(), v.end(), []()->user_type{return (std::rand() + std::rand() + std::rand()) % 100; });

	std::generate(v.begin(), v.end(), []()->user_type{	user_type s(15, ' ');
	                                                    user_type char_set_l(_char_set);
														std::generate(s.begin(), s.end(), [&char_set_l]()->char{
															int i = std::rand() % char_set_l.size();
															char ch = char_set_l.at(i);
															char_set_l.erase(i, 1);
															return ch;
														});
											            return s; } );

	//std::for_each(v.begin(), v.end(), [](user_type x) { std::cout << x << " "; }); std::cout << std::endl;

	my_sort( v.begin(), v.end() );

	std::for_each(v.begin(), v.end(), [](user_type x) { std::cout << x << std::endl; }); std::cout << std::endl;

	DEBUGPRINT("argc = %d", argc);
	DEBUGPRINT("Hello world.");
	DEBUGPRINT( "%s %s%c", "Hello", "world", '.' );
	DEBUGPRINT( "%s.", "Hello world" );	
	DEBUGPRINT("%s", wstring_to_string( _T("не много русской кодировка.") ).c_str() );
	DEBUGPRINT("|%s|", wstring_to_string(argv[0]).c_str());

	return 0;
}

