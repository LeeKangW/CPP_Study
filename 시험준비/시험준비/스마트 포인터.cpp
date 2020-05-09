#include<iostream>
#include<memory>

using namespace std;

class Dog {
private:
	int n;
public:
	Dog() { cout << "생성" << endl; }
	~Dog() { cout << "소멸" << endl; }

	void show() {
		cout << "Dog입니다." << endl;
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
