#include"default.h"

class Dog {
public:
	void operator()(int n) {
		cout << n << " - �θ��̳���?" << endl;
	}
};

int main() {
	Dog dog; // dog�� ȣ�Ⱑ�� ��ü�̰�, Dog�� ȣ�Ⱑ�� Ÿ���̴�.

	dog(2020);
}