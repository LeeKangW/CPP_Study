#include<iostream>

using namespace std;

class Dog
{
public:
	void operator()(int n)
	{
		cout << n << "ют╥б" << endl;
	}
};
int main()
{
	Dog dog;
	dog(333);
}