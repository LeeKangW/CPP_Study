#include"default.h"
#include<string>

int main() {
	int num = 0B0111'1111'1111'1111'1111'1111'1111'1111;

	cout << "num의 메모리 크기는 " << sizeof(num) << "바이트" << endl;
	cout << "num에 저장된 값은 " << num << endl;

	string s{ to_string(num) };

	cout << "num을 글자로 저장하려면 " << size(s) << "바이트가 필요합니다." << endl;
	
}