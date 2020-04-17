#include"default.h"

int main() {

	int* p;
	p = new int[3]{ 1,2,3 };

	cout << "HEAP에 할당한 int의 값" << endl;
	for (int i = 0; i < 3; ++i)
		cout << p[i] << endl;

	cout << endl;
	cout << "p의 주소: " << &p << endl;
	cout << "p의 크기: " << sizeof(p) << "바이트" << endl;

	//비교를 위한 int

	int n{ 2020 };
	cout << "n의 주소: " << &n << endl;

	cout << endl;

	for (int i = 0; i < 3; ++i)
		cout << "p[i]의 주소: " << &p[i] << endl;

	delete[] p;
}