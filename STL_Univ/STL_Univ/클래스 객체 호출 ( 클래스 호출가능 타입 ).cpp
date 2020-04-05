#include"default.h"

class Dog {
public:
	void operator()(int n) {
		cout << n << " - 부르셨나요?" << endl;
	}
};

int main() {
	Dog dog; // dog는 호출가능 객체이고, Dog는 호출가능 타입이다.

	dog(2020);
}