#include"default.h"
#include<array>


int main() {
	array<int, 5> a;
	array<int, 10> b;

	cout << "a�� ũ�� - " << sizeof(a) << endl;
	cout << "b�� ũ�� - " << sizeof(b) << endl;

	cout << "a�� �����Ͱ� ����� �޸� - " << a.data() << endl;
	cout << "b�� �����Ͱ� ���ڿ��� �޸� - " << b.data() << endl;

	int n{ 2020 };
	cout << "STACK �񱳸� ���� ���� n�� ���� - " << &n << endl;


}