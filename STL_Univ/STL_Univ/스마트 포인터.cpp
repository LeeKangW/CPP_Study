#include"default.h"
#include<memory>

class Dog {
	int n;

public:
	// 생성과 소멸 관찰용
	// Dog() { cout << "생성" << endl; }
	// ~Dog() { cout << "소멸" << endl; }

	void show() {
		cout << "Dog입니다만"<< endl;
	}
};

void f(unique_ptr<Dog>);

int main() {

	unique_ptr<Dog> p{ new Dog };	// 자원 확보

	p->show();						// 자원 사용

	f(move(p));						// 자원을 사용한다.
	// cout << sizeof(p) << endl;		// unique_ptr 자원 크기
}

void f(unique_ptr<Dog> pDog) {
	pDog->show();
	cout << "f" << endl;
}
