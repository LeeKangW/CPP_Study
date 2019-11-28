#include<iostream>

using namespace std;
void callsbyrefer(int& a) {
	a++;
}
void callbypointer(int* b) {
	*b += 1;
}
int main() {

	int a = 3;
	int b = 4;
	callsbyrefer(a);
	callbypointer(&b);
	cout << a << endl;
	cout << b << endl;
}
