// cpp06.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
// Chacked by Visual Studio 2013 Update 4

#include "stdafx.h"
#include <iostream>

class A{};
class B : public A{};
class C{};

int _tmain(int argc, _TCHAR* argv[])
{
	std::wcout << "----- static_assert sample" << std::endl;

	static_assert(std::is_base_of<A, B>::value == true, "B is based of A");		// ○
//	static_assert(std::is_base_of<A, C>::value == true, "C is based of A");		// ×
	static_assert(std::is_base_of<A, C>::value == false,"C is not based of A");	// ○

	return 0;
}
