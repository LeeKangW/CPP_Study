#include"default.h"

int main() {

	int* p;
	p = new int[3]{ 1,2,3 };

	cout << "HEAP�� �Ҵ��� int�� ��" << endl;
	for (int i = 0; i < 3; ++i)
		cout << p[i] << endl;

	cout << endl;
	cout << "p�� �ּ�: " << &p << endl;
	cout << "p�� ũ��: " << sizeof(p) << "����Ʈ" << endl;

	//�񱳸� ���� int

	int n{ 2020 };
	cout << "n�� �ּ�: " << &n << endl;

	cout << endl;

	for (int i = 0; i < 3; ++i)
		cout << "p[i]�� �ּ�: " << &p[i] << endl;

	delete[] p;
}