#include"default.h"
#include"String.h"

String g{ "COVID-19" };			// g�� DATA,"COVID-19"�� HEAP�� ����
int main() {
	
	String s{ "COVID-19" };		// s�� STACK,"COVID-19"�� HEAP�� ����

	int n{ 2020 };

	cout << "�������� n�� ���� -" << &n << endl; // n�� STACK

}