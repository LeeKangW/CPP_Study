#include<iostream>

using namespace std;

void f(int n)
{
	cout << "F: " << n << endl;
}

int main()
{
	f(1); // 일반 호출
	(*f)(2); // 함수이름이 함수 시작번지(주소)를 가리키는 포인터
	
	int a = 0;

	void* p = f; // 함수의 시작번지(주소)를 포인터에 저장

	cout << "함수 f의 시작 주소 :" << p << endl;
}