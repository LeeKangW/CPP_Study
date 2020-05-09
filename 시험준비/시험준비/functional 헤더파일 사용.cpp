#include<iostream>
#include<functional>
using namespace std;

void f(int n)
{
	cout << n << "- ��¥ �׳� �Լ�" << endl;
}
class Dog {
public:
	void operator()(int n) {
		cout << n << "- funtion object" << endl;
	}
};

void(*fp)(int) = f;

auto lambda = [](int n) {
	cout << n << "- �̸� ���� �Լ� ���� " << endl;
};

int main() {
	function<void(int)> func;

	cout << typeid(func).name() << endl; // func�� function ��ü�̴�.

	func = f;
	func(1);

	func = Dog();
	func(2);

	func = fp;
	func(3);

	func = lambda;
	func(4);
}