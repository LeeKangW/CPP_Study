#include<iostream>
#include<tuple>

using namespace std;

class Animal {

public:
	int a() {
		cout << "??" << endl;
	}
	int a(int _a) {
		cout << _a << endl;
	}
	int a(string b) {
		cout << b << endl;
	}
};
tuple<int, int>Add(){

	int a = 0, b = 0;
	cout << "ù �� ° ���� : ";
	cin >> a;

	cout << "�� �� ° ���� : ";
	cin >> b;

	return make_tuple(a, b);
}

int main() {

	tuple<int, int> b;
	b = Add();
	
	int result = get<0>(b) + get<1>(b);

	cout << result << endl;


	
}