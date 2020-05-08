#include<iostream>

using namespace std;

class Model {
	char* data;
	size_t size;
public:
	Model() { cout << "기본생성자" << endl; }
	Model(size_t size) :size{ size } {
		data = (char*)&size;
		

		cout << "매개변수가 있는 생성자" << endl;

	}
	~Model() {
		cout << "소멸자" << endl; 
	}
	Model(const Model& model) :size{ model.size }
	{
		data = new char[strlen(model.data) + 1];
		data = model.data;

		cout << "복사생성자" << endl;
	}
	Model& operator=(const Model& model) {
		size = model.size;

		data = new char[strlen(model.data) + 1];
		data = model.data;

		cout << "대입 연산자" << endl;
		return *this;
	}
	
};

int main() {
	Model a;
	Model b{ 1000 };
	Model c = b;
	a = c;


}