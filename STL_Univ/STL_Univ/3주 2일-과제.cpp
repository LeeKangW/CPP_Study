#include"default.h"
#include<memory>

class Dog {
	int n;

public:
	// ������ �Ҹ� ������
	// Dog() { cout << "����" << endl; }
	// ~Dog() { cout << "�Ҹ�" << endl; }
	void show() {
		cout << "Dog�Դϴٸ�" << endl;
	}
};

int main() {

	{
		auto dog = make_unique<Dog>();
		
		dog->show();
	}

	unique_ptr<Dog[]> dogs{ new Dog[3] };
	
	
}