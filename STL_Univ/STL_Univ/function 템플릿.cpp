#include"default.h"
#include<functional>

void f(int n) {
	cout << n << "- ��¥ �׳� �Լ�" << endl;
}

class Dog {
public:
	void operator()(int n) {
		cout << n << "- function object" << endl;
	}
};

void(*fp)(int) = f; // �Լ� ������
// void �� ��ȯ �ǰ�, int�� �Ű������� �޴� ���̶�� �����ϸ� ��.

// ��ȯ��(*p)(�Ű�����) = �Լ��̸� ..... �̷� ����


auto lambda = [](int n) {
	cout << n << "- �̸� ���� �Լ� ����" << endl;
};

int main() {

	function<void(int)>func;

	cout << typeid(func).name() << endl;	// func�� fucntion�� ��ü�̴�.

	func = f;
	func(1);

	func = Dog();
	func(2);

	func = fp;
	func(3);

	func = lambda;
	func(4);
}