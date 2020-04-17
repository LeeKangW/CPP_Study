#include"default.h"
#include<string>

void f(int, double, string);
void reverse_f(string, double, int);

int main() {
	int i{ 1 };
	double d{ 2 };
	string s{ "3" };

	f(i, d, s);			// i, d, s 로 호출

	reverse_f(s, d, i); // 순서를 거꾸로 호출
}

void f(int i, double d, string s) {
	cout << endl << "f" << endl;
	cout << "int 주소: " << &i << ", 크기: " << sizeof(i) << "바이트" << endl;
	cout << "double 주소: " << &d << ", 크기: " << sizeof(d) << "바이트" << endl;
	cout << "string 주소: " << &s << ", 크기: " << sizeof(s) << "바이트" << endl;
}

void reverse_f(string s, double d, int i)
{
	cout << endl << "reverse_f" << endl;
	cout << "string 주소: " << &s << ", 크기: " << sizeof(s) << "바이트" << endl;
	cout << "double 주소: " << &d << ", 크기: " << sizeof(d) << "바이트" << endl;
	cout << "int 주소: " << &i << ", 크기: " << sizeof(i) << "바이트" << endl;
}