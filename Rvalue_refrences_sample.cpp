// cpp00.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <memory>

class MyClass {
public:
	MyClass() {
		d = 1;
	}
	double d;
};

int f(void){ return(2); }

int _tmain(int argc, _TCHAR* argv[])
{
	MyClass	x;
	MyClass	*p = &x;
	MyClass	&q = x;

	std::wcout << "----- Rvalue refrences sample" << std::endl;
	std::wcout << p->d << std::endl;			// 1, p経由で x の中身表示
	std::wcout << p << std::endl;				// 0113F7C8, pのアドレス表示(1)
	std::wcout << q.d << std::endl;				// 1, q経由で x の中身表示

	std::wcout << sizeof(MyClass) << std::endl;	// 8, MyClassのサイズ
	std::wcout << sizeof(p) << std::endl;		// 4, p のポインタサイズ
	std::wcout << sizeof(&q) << std::endl;		// 4, q のポインタサイズ
	std::wcout << &q << std::endl;				// 0113F7C8, qのアドレス表示 (1)と同じ
	std::wcout << sizeof(x) << std::endl;		// 8, xの実態のサイズ

	std::wcout << "------" << std::endl;
	int &&z = f();
	std::wcout << z << std::endl;				// 2, Rvalueで受け取った値

	std::wcout << "------" << std::endl;
	MyClass *pp = nullptr, *qq = nullptr;
	pp = new MyClass();
	std::wcout << pp << std::endl;				// 01192710, ppのアドレス表示(2)
	qq = std::move(pp);
	std::wcout << qq << std::endl;				// 01192710, move()を受けたqqアドレス表示 (2)と同じ
	std::wcout << qq->d << std::endl;			// 1
												// 以下2行、規定では不定なはずなので、本来は ppにアクセスしてはいけない
	std::wcout << pp->d << std::endl;			// 1
	std::wcout << pp << std::endl;				// 01192710, move()後のppアドレス表示 (2)と同じ

	std::wcout << "------" << std::endl;
	std::unique_ptr<MyClass>  p0(new MyClass()), q0;
	//	q0 = p0;								// コピーは出来ない、コンパイルエラーになる
	q0 = std::move(p0);							// p0 を q0 に move()する
	std::wcout << q0->d << std::endl;			// 1
//	std::wcout << p0->d << std::endl;			// p0は move後なので、実行時エラーになった

	return 0;
}
