#include<iostream>
#define function 1

/*
	try - try 내부에서 예외가 있는지 탐색을 하는 부분
	throw - try에서 예외를 탐색하면 throw의 인자로 준 변수를 catch로 던집니다.
	catch - throw에서 던진 변수를 인자로 받아서 catch 내부에 프로그래머가 정의한 예외처리르 실시합니다.
*/
using namespace std;

#pragma region  메인문만 ( function == 0) 함수로 구현 ( function == 1) 사용 예제
#if function == 0


int main() {
	cout << "메인문만 사용 " << endl;
	int a, b;
	try {
		cin >> a;
		cin >> b;

		if (b <= 0) {
			// 예외 발생시,
			throw b; //throw를 통해 변수 b를 catch의 파라미터로 보냄.
		}
		cout << "[work]" << endl;
		cout << "a:" << a << ", b:" << b << endl;
		cout << "a/b: " << a / b << endl;
	}
	catch (int expn) { // throw에서 보낸 b 인자를 expn으로 받는다.
		cout << "[error]" << endl;
		cout << "can't use this :" << expn << endl;
	}

	return 0;
}

#elif function == 1

int divide(int a, int b) {
	if (b == 0) {
		throw b;
	}
	return a / b;
}

int main() {
	cout << "함수 사용 " << endl;
	int a, b;
	try {
		cin >> a;
		cin >> b;

		cout << "a/b : "<<divide(a, b) << endl;
	}
	catch (int ex) {
		cout << "[error]" << endl;
		cout << "Can't use : " << ex << endl;
	}
}


#endif
#pragma endregion