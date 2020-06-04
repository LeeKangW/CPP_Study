#include"default.h"

template<typename Iter>
void change(Iter&, Iter&);

int main() {
	int a{ 1 };
	int b{ 2 };

	change(a, b);
	//change<string>(a,b);   // ���� ����

	cout << a << "," << b << endl;
}

template <typename Iter>
void change(Iter& a, Iter& b) {
	Iter t{ a };
	
	a = b;
	b = t;
}