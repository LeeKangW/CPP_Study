#include<iostream>

using namespace std;

void f(int n)
{
	cout << "F: " << n << endl;
}

int main()
{
	f(1); // �Ϲ� ȣ��
	(*f)(2); // �Լ��̸��� �Լ� ���۹���(�ּ�)�� ����Ű�� ������
	
	int a = 0;

	void* p = f; // �Լ��� ���۹���(�ּ�)�� �����Ϳ� ����

	cout << "�Լ� f�� ���� �ּ� :" << p << endl;
}