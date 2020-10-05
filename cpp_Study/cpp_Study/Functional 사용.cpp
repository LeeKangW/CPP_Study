#include<iostream>
#include<functional>

using namespace std;

void f(int n)
{
	cout << n << " - 함수" << endl;
}

class Dog
{
public:
	void operator()(int n)
	{
		cout << n << " - 매소드 " << endl;
	}
};

int main()
{
	function<void(int)> func;

	func = f;
	func(1);

	func = Dog();
	func(2);

	void(*fp)(int) = f;
	func = fp;
	func(3);

	func = [](int n) { cout << n << " - 람다" << endl; };
	func(4);

}