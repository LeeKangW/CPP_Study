#include<iostream>

using namespace std;
class Animal {
private:
	int a = 0;
public:
	void virtual Print() {
	cout<< "���� A"<<endl;
	}
	void AP() {

	}
};

class Dog :public Animal {
	
	void Print() override {
		cout << "���� B" << endl;
	}
};
int main() {
	Animal* a = new Dog();
	a->Print();
}