#include<iostream>
#include<cmath>
using namespace std;

void f(int n) {
	cout << "f: " << n << endl;
}
int main() {
	f(1); // �Ϲ� ȣ��
	(*f)(2); // �Լ� �̸��� �Լ��� ���۹����� ����Ű�� ������

	void* p = f; // �Լ��� ���۹����� �����Ϳ� ����

	cout << "�Լ� f�� �ּ� :" << p << endl;

	int n{};
	cout << "������ �ּ�" << &n << endl;

	(*(void(*)(int))p)(3); // �ּ� p�� �Լ��� �ٲ� ���� 3���� ȣ��

}