#include"default.h"
#include<functional>

void f(int n) {
	cout << n << "- 진짜 그냥 함수" << endl;
}

class Dog {
public:
	void operator()(int n) {
		cout << n << "- function object" << endl;
	}
};

void(*fp)(int) = f; // 함수 포인터
// void 형 반환 되고, int를 매개변수로 받는 것이라고 생각하면 됨.

// 반환형(*p)(매개변수) = 함수이름 ..... 이런 느낌


auto lambda = [](int n) {
	cout << n << "- 이름 없는 함수 람다" << endl;
};

int main() {

	function<void(int)>func;

	cout << typeid(func).name() << endl;	// func는 fucntion의 객체이다.

	func = f;
	func(1);

	func = Dog();
	func(2);

	func = fp;
	func(3);

	func = lambda;
	func(4);
}