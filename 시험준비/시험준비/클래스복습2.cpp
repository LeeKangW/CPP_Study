#include<iostream>
using namespace std;

class Model {
private:
	static int id;

public:
	Model() {
		id += 1;
		cout <<"���� : "<< id << endl;
	}
	~Model() {
		cout << "�Ҹ� : "<< id << endl;
		--id;
	}
};
int Model::id = 0;

int main() {
	Model a[10];
}