#include"default.h"
#include"String.h"

#define Q1 1
#undef Q1
int main() {

#if Q1
	String s{ "힘내라 대한민국!" };

	cout << "s의 크기 :" << sizeof(s) << "바이트" << endl;
	cout << "s의 번지:" << &s << endl;

	int n{ 2020 };
	cout << "n의 번지: " << &n << endl;

	cout << endl;

	cout << "s가 할당한 메모리의 번지: " << static_cast<void*>(&s[0]) << endl;

	int* p = new int{ 777 };
	cout << "HEAP의 번지:" << p << endl;
	cout << "p의 번지:" << &p << endl;
#else
	String* p = new String{ "힘내라 대한민국" };

	cout << "s의 크기 :" << sizeof(p) << "바이트" << endl;
	cout << "s의 번지:" << &p << endl;

	int n{ 2020 };
	cout << "n의 번지: " << &n << endl;

	cout << endl;

	cout << "s가 할당한 메모리의 번지: " << static_cast<void*>(&p[0]) << endl;

	int* k = new int{ 777 };
	cout << "HEAP의 번지:" << k << endl;
	cout << "p의 번지:" << &k << endl;

#endif
}