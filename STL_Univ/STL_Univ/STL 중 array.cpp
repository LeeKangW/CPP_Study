#include"default.h"
#include<array>


int main() {
	array<int, 5> a;
	array<int, 10> b;

	cout << "a의 크기 - " << sizeof(a) << endl;
	cout << "b의 크기 - " << sizeof(b) << endl;

	cout << "a의 데이터가 저장된 메모리 - " << a.data() << endl;
	cout << "b의 데이터가 저자오딘 메모리 - " << b.data() << endl;

	int n{ 2020 };
	cout << "STACK 비교를 위한 변수 n의 번지 - " << &n << endl;


}