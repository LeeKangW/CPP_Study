#include<iostream>

using namespace std;

class Model {
	char* data;
	size_t size;
public:
	Model() { cout << "�⺻������" << endl; }
	Model(size_t size) :size{ size } {
		data = (char*)&size;
		

		cout << "�Ű������� �ִ� ������" << endl;

	}
	~Model() {
		cout << "�Ҹ���" << endl; 
	}
	Model(const Model& model) :size{ model.size }
	{
		data = new char[strlen(model.data) + 1];
		data = model.data;

		cout << "���������" << endl;
	}
	Model& operator=(const Model& model) {
		size = model.size;

		data = new char[strlen(model.data) + 1];
		data = model.data;

		cout << "���� ������" << endl;
		return *this;
	}
	
};

int main() {
	Model a;
	Model b{ 1000 };
	Model c = b;
	a = c;


}