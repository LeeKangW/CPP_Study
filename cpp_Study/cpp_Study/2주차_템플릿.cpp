#include<iostream>
using namespace std;

template<class T>
class A
{
private:
	T t;
public:
	A(T rhs) { t = rhs; }
};

template<class T>
T Sum(T a, T b)
{
	cout << typeid(T).name() << " : ";

	return a + b;
}

template<>
char Sum(char a, char b)
{
	cout << "char" << " : ";
	cout << a << "+" << b;
	return ' ';
}

int main()
{
	int a = 1;
	int b = 2;
	double da = 1.5f;
	double db = 2.f;

	string s = "a";
	string s2 = "b";

	char c = 'a';
	char c2 = 'b';

	cout << Sum(a, b) << endl;
	cout << Sum(da, db) << endl;
	cout << Sum(s, s2) << endl;
	cout << Sum(c, c2) << endl;

}