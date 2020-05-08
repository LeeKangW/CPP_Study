#include<iostream>
using namespace std;

class Model {
private:
	int num;
	char* data;
public:
	Model(int num) :num{ num } { 
		cout << "持失切" << endl; 
	}
	
	Model(Model&& model) :num{ model.num } {
		num = model.num;
		model.num = 0;

		cout << num << endl;
		cout << model.num << endl;
		cout << "戚疑持失切" << endl;
	}
};
int main() {
	Model a{ 1000 };
	Model b = move(a);
}