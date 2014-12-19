// cpp10.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
// Chacked by Visual Studio 2013 Update 4

#include "stdafx.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	std::wcout << "----- decltype sample" << std::endl;

	int a;
	decltype(a) b;
	typedef decltype(a) MyInt;
	MyInt c;

	std::cout << typeid( a ).name() << std::endl;		// int
	std::cout << typeid( b ).name() << std::endl;		// int
	std::cout << typeid( c ).name() << std::endl;		// int
	std::cout << typeid( MyInt ).name() << std::endl;	// int
 
	return 0;
}
