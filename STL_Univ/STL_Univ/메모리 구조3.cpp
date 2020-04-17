#include"default.h"
#include"String.h"

#define Q1 1
#undef Q1
int main() {

#if Q1
	String s{ "������ ���ѹα�!" };

	cout << "s�� ũ�� :" << sizeof(s) << "����Ʈ" << endl;
	cout << "s�� ����:" << &s << endl;

	int n{ 2020 };
	cout << "n�� ����: " << &n << endl;

	cout << endl;

	cout << "s�� �Ҵ��� �޸��� ����: " << static_cast<void*>(&s[0]) << endl;

	int* p = new int{ 777 };
	cout << "HEAP�� ����:" << p << endl;
	cout << "p�� ����:" << &p << endl;
#else
	String* p = new String{ "������ ���ѹα�" };

	cout << "s�� ũ�� :" << sizeof(p) << "����Ʈ" << endl;
	cout << "s�� ����:" << &p << endl;

	int n{ 2020 };
	cout << "n�� ����: " << &n << endl;

	cout << endl;

	cout << "s�� �Ҵ��� �޸��� ����: " << static_cast<void*>(&p[0]) << endl;

	int* k = new int{ 777 };
	cout << "HEAP�� ����:" << k << endl;
	cout << "p�� ����:" << &k << endl;

#endif
}