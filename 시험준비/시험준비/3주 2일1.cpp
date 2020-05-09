#include<iostream>
#include<cmath>
using namespace std;

void f(int n) {
	cout << "f: " << n << endl;
}
int main() {
	f(1); // 일반 호출
	(*f)(2); // 함수 이름은 함수의 시작번지를 가리키는 포인터

	void* p = f; // 함수의 시작번지를 포인터에 저장

	cout << "함수 f의 주소 :" << p << endl;

	int n{};
	cout << "스택의 주소" << &n << endl;

	(*(void(*)(int))p)(3); // 주소 p를 함수로 바꿔 인자 3으로 호출

}