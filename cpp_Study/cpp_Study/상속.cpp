#include<iostream>

using namespace std;
class A {
private:
	int a = 0;
public:
	void virtual Print() {
	cout<< "나는 A"<<endl;
	}
	void AP() {

	}
};

class B :public A {
	
	void Print() override {
		cout << "나는 B" << endl;
	}
};
int main() {
	A* a = new B();
	a->Print();
}