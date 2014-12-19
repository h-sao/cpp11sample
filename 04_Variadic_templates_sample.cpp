// cpp04.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
// Chacked by Visual Studio 2013 Update 4

#include "stdafx.h"
#include <iostream>

// 可変長 関数テンプレート
template <class ...A> int f(A... arg)
{
	// 可変長テンプレートの要素数を求めることが出来る sizeof...()
	return sizeof...(arg);
}

// 可変長 クラステンプレート
template<class ... B> class Hoge{
public:
	Hoge( B... args ){
		std::cout << sizeof...(B) << std::endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	std::wcout << "----- Variadic templates sample" << std::endl;

	// --------------------------
	// 可変長 関数テンプレート
	// --------------------------
	std::wcout << "-- function --" << std::endl;
	// template <int,int,int,int,int> int f( int, int, int, int, int){} と同じ意味
	std::cout << f(1, 2, 3, 4, 5) << std::endl;	// 5
	std::cout << f("a", "b") << std::endl;		// 2
	std::cout << f(1, "b", 3) << std::endl;		//3

	// --------------------------
	// 可変長 クラステンプレート
	// --------------------------
	std::wcout << "-- class --" << std::endl;
	Hoge<>				b0{};				          // 0
	Hoge<int>			b1{ 1 };			        // 1
	Hoge<int, float>	b2{ 10, 3.14f };	// 2

	return 0;
}
