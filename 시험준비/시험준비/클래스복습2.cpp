#include<iostream>
using namespace std;

class Model {
private:
	static int id;

public:
	Model() {
		id += 1;
		cout <<"»ý¼º : "<< id << endl;
	}
	~Model() {
		cout << "¼Ò¸ê : "<< id << endl;
		--id;
	}
};
int Model::id = 0;

int main() {
	Model a[10];
}