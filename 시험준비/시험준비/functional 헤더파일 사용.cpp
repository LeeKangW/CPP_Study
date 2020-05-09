#include<iostream>
#include<functional>
using namespace std;

void f(int n)
{
	cout << n << "- 진짜 그냥 함수" << endl;
}
class Dog {
public:
	void operator()(int n) {
		cout << n << "- funtion object" << endl;
	}
};

void(*fp)(int) = f;

auto lambda = [](int n) {
	cout << n << "- 이름 없는 함수 람다 " << endl;
};

int main() {
	function<void(int)> func;

	cout << typeid(func).name() << endl; // func는 function 객체이다.

	func = f;
	func(1);

	func = Dog();
	func(2);

	func = fp;
	func(3);

	func = lambda;
	func(4);
}