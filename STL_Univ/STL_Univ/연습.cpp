#include<iostream>
#include<fstream>
#include<random>

using namespace std;

default_random_engine dre;
uniform_int_distribution<> uid(1, 10);

class A {
private:
	int num;

public:
	A() = default;

	int getNum() {
		return num;
	}
	void show() const{
		cout << num << endl;
	}
};

int main() {
	/*
	ofstream out("ป๙วร.txt");

	for (int i = 0; i < 1'000; ++i)
	{
		A a;
		out << a.getNum()<<' ';
	}
	*/
	ifstream in("ป๙วร.txt");

	vector<A> v;
	v.resize(1'000);

	in.read((char*)v.data(), sizeof(A));

	for (const A& a : v)
		a.show();
}