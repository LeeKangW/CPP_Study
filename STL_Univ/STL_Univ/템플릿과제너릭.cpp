#include"default.h"

template<typename T>
void change(T&, T&);

int main() {
	int a{ 1 };
	int b{ 2 };

	change(a, b);
	//change<string>(a,b);   // 정식 사용법

	cout << a << "," << b << endl;
}

template <typename T>
void change(T& a, T& b) {
	T t{ a };
	
	a = b;
	b = t;
}