#include"default.h"
#include<vector>
#include<algorithm>

//#define Q1

int main() {
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	//[문제]를 해결하는 코드를 작성.

#ifdef Q1 // 원소 3 제거
	/*
	auto i = remove(v.begin(), v.end(), 3);
	v.erase(i);
	*/
	v.erase(remove(v.begin(), v.end(), 3));

#endif
#ifndef Q1 // 홀수 제거
	/*
	v.erase(remove_if(v.begin(), v.end(), [](int i) {
		return i & 1;
		}),v.end());
		*/
		// C++ 20 방법
	erase_if(v, [](int n) {return n & 1; });
#endif
	for (int n : v) // int의 경우 복사나 const &나 차이없음.
		cout << n << ' '; 
	cout << endl;
}