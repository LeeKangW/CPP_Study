#include"default.h"
#include<memory>

class Dog {
	int n;

public:
	// ������ �Ҹ� ������
	// Dog() { cout << "����" << endl; }
	// ~Dog() { cout << "�Ҹ�" << endl; }

	void show() {
		cout << "Dog�Դϴٸ�"<< endl;
	}
};

void f(unique_ptr<Dog>);

int main() {

	unique_ptr<Dog> p{ new Dog };	// �ڿ� Ȯ��

	p->show();						// �ڿ� ���

	f(move(p));						// �ڿ��� ����Ѵ�.
	// cout << sizeof(p) << endl;		// unique_ptr �ڿ� ũ��
}

void f(unique_ptr<Dog> pDog) {
	pDog->show();
	cout << "f" << endl;
}
