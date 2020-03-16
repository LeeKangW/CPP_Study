#include<iostream>

using namespace std;

class X {
private:
	int num;
public:
	X(int k) :num(k){}
};

void change(X& a, X& b) {
	X c{ a };
	a = b;
	b = c;
}

int main() {
	X a{ 1 };
	X b{ 2 };
	
	
	change(a, b);

	cout << a << endl;
}