#include"default.h"
#include"String.h"
#include<algorithm>

template<class T>
T my_max_element(T b,T e);

int main() {
	String str{ "The quick brown fox jumps over the lazy dog" };

	auto p = my_max_element(str.begin(), str.end());

	cout << "최대: " << *p << endl;
}

template<class T>
T my_max_element(T b, T e) {
	
	/*
	//검사할 원소가 없다면
	if (b == e)
		return e;	// 마지막 위치를 리턴

	// 제일 처음 원소의 값을 최대값으로 초기화
	auto max_value = *b;
	// 제일 처음 원소의 위치를 최댓값인 위치로 초기화
	T max_position = b;

	while (b != e) {
		if (max_value < *b) {
			max_position = b;
			max_value = *b;
		}
		++b;
	}
	return max_position; // 최댓값의 위치를 리턴
	*/

	if (b == e)
		return e;

	T max = b;

	while (++b != e)
		if (*max < b)
			max = b;

	return max;
}
