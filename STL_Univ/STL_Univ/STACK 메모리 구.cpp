#include"default.h"
#include<string>

void f(int, double, string);
void reverse_f(string, double, int);

int main() {
	int i{ 1 };
	double d{ 2 };
	string s{ "3" };

	f(i, d, s);			// i, d, s �� ȣ��

	reverse_f(s, d, i); // ������ �Ųٷ� ȣ��
}

void f(int i, double d, string s) {
	cout << endl << "f" << endl;
	cout << "int �ּ�: " << &i << ", ũ��: " << sizeof(i) << "����Ʈ" << endl;
	cout << "double �ּ�: " << &d << ", ũ��: " << sizeof(d) << "����Ʈ" << endl;
	cout << "string �ּ�: " << &s << ", ũ��: " << sizeof(s) << "����Ʈ" << endl;
}

void reverse_f(string s, double d, int i)
{
	cout << endl << "reverse_f" << endl;
	cout << "string �ּ�: " << &s << ", ũ��: " << sizeof(s) << "����Ʈ" << endl;
	cout << "double �ּ�: " << &d << ", ũ��: " << sizeof(d) << "����Ʈ" << endl;
	cout << "int �ּ�: " << &i << ", ũ��: " << sizeof(i) << "����Ʈ" << endl;
}