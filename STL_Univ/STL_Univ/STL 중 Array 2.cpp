#include"default.h"
#include<array>
#include"String.h"


int main() {

	array<String, 5> words{ "corona,""virus","world","crisis","pandemic" };

	cout << words[0] << endl;	//배열과 같은 사용법

	auto p = words.begin();		 // words의 첫 원소를 가리키는 반복자
	cout << *p << endl;			// 반복자 p가 가리키는 것은 바로 첫번째 원소

	++p;						// 다음 원소로 이동
	cout << *p << endl; 

	for (int i = 0; i < words.size(); ++i) // 모든 컨테이너는 size 멤버를 제공
		cout << words[i] << " ";
	cout << endl;

	for (const String& word : words)			// range-based for로 순회
		cout << word << " ";
	cout << endl;

	// 범위를 벗어난 경우를 굳이 점검하고 싶다면

	try {
		// 이렇게 쓰면 안되고
		// cout << "이건 없는 원소잖아?" << words[-1] << endl;
		cout << "이건 없는 원소잖아?" << words.at(-1) << endl;
		// 예외 떄문에 endl이 출력되지 않을걸!
	}
	catch (const exception& e) {
		cout << "C++ 에서 예외를 사용하다니? -" << e.what() << endl;
	}
}