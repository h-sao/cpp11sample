// cpp03.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
// Chacked by Visual Studio 2013 Update 4

#include "stdafx.h"
#include <iostream>

class A{
public:
	int a = 42;
	A(){
		a = 10;		// こちらが有効
	}
};

class B{
public:
	int b;
	B() : b(42){ }
};

int _tmain(int argc, _TCHAR* argv[])
{
	std::wcout << "----- Non-static data member initializers sample" << std::endl;

	A *pa = new A();
	std::cout << pa->a << std::endl;	// 10

	B *pb = new B();
	std::cout << pb->b << std::endl;	// 42

	return 0;
}
