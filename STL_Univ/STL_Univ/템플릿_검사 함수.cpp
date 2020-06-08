#include"default.h"
#include<string>

template<class T>
T add(T a, T b) {
	if constexpr (is_arithmetic<T>()) // T가 산술 가능한 타입이니 ?
	{
		cout << typeid(T).name() << "는 산술연산이 가능합니다." << endl;
		return a + b;
	}
	else {
		cout << "더할 수 없는 타입니다." << endl;
		return a;
	}
}

class Dog { };

int main() {

	// 함수 템플릿 add를 작성하라.
	cout << add<int>(1, 2) << endl;
	cout << add<string>("1"s, "2"s) << endl;
	cout << add<string>("a", "b") << endl;

	// cout << add("ab", "cd") << endl;	// const char* 로 판단해서 돌아감. -> 포인터끼리는 더할 수 없음.

	// add<Dog>(Dog(), Dog());				// 이건 안됨
}
