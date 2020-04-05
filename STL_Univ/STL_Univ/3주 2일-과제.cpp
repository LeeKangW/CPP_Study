#include"default.h"
#include<memory>

class Dog {
	int n;

public:
	// 积己苞 家戈 包蔓侩
	// Dog() { cout << "积己" << endl; }
	// ~Dog() { cout << "家戈" << endl; }
	void show() {
		cout << "Dog涝聪促父" << endl;
	}
};

int main() {

	{
		auto dog = make_unique<Dog>();
		
		dog->show();
	}

	unique_ptr<Dog[]> dogs{ new Dog[3] };
	
	
}