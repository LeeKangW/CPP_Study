#include<iostream>
using namespace std;

class X {
private:
	int num;
public:
	X(int num) :num{ num } {}
	friend ostream& operator<<(ostream& os, const X& x);
};
ostream& operator<<(ostream& os, const X& x) {
	os << x.num;
	return os;
}

void change(X& a, X& b);
int main() {
	X a{ 1 };
	X b{ 2 };

	change(a, b);

	cout << a << "," << b << endl;
}
void change( X& a,  X& b) {
	X c{ b };
	b = a;
	a = c;
}