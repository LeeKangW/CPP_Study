#include<iostream>

using namespace std;

class A
{
private:
	int a = 0;
public:
	A(int n)
	{
		a = n;
	}

	A operator+(A& rhs)
	{
		return A(a + rhs.a);
	}

	void show()
	{
		cout << a << endl;
	}
};

int main()
{
	A a(2);
	A b(3);
	A c(4);

	c = a + b;
	
	c.show();
}