// cpp02.cpp : Defines the entry point for the console application.
//
// Chacked by Visual Studio 2015 Preview

#include "stdafx.h"
#include <iostream>

struct X {
	void f()& {
		std::cout << "L value" << std::endl;
	}
	void f() && {
		std::cout << "R value" << std::endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	X m;

	std::wcout << "----- ref-qualifiers sample" << std::endl;
	m.f();			// L value
	std::move(m).f();	// R value

	return 0;
}

