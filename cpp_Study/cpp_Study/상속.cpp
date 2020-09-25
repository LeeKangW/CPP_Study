#include<iostream>

using namespace std;
class Animal {
private:
	int a = 0;
public:
	void virtual Print() {
	cout<< "나는 A"<<endl;
	}
	void AP() {

	}
};

class Dog :public Animal {
	
	void Print() override {
		cout << "나는 B" << endl;
	}
};
int main() {
	Animal* a = new Dog();
	a->Print();
}