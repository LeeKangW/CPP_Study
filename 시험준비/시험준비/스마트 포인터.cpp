#include<iostream>
#include<memory>

using namespace std;

class Dog {
private:
	int n;
public:
	Dog() { cout << "����" << endl; }
	~Dog() { cout << "�Ҹ�" << endl; }

	void show() {
		cout << "Dog�Դϴ�." << endl;
	}
};

void f(unique_ptr<Dog>);
int main() {

	{
		auto dog = make_unique<Dog>();
	}
	unique_ptr<Dog> dogs{ new Dog[3] };
	
}
void f(unique_ptr<Dog> pDog) {
	pDog->show();
}
