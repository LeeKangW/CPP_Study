#include"default.h"

int main() {

	auto callableType = []() {
		cout << "안녕? 난 람다라고 해!" << endl;
	};

	// 호출 가능 타입은 ()를 붙일 수 있다.
	callableType();

	cout << typeid(callableType).name() << endl;

	/*

	이렇게 하면 호출이 되지 않음.
	-> 호출가능 타입인 람다를 호출하지 않았기 때문.

	[]() {
		cout << "안녕? 난 람다라고 해!" << endl;
	};
	*/
}