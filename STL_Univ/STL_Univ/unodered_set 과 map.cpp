#include<iostream>
#include<unordered_set>
#include<random>
#include<thread>
#include"String.h"
#include"save.h"

using namespace std;

//2020.5.25 월
//
// unordered_set / unordered_map
//
// unordered associative container
// 1. 순서가 없다.
// 2. 메모리 구조를 출력 
// 3. String을 이 컨테이너의 원소로 되도록 하려면

// hash 함수를 쓰기 때문에 찾을 때 O(1) 이 걸린다.

int main() {
	/*	initializer_list<int> x = { 1,2,3,4,5,6,7 };
	// -> 클래스 생성자로 많이 씀.
	// auto x = { 1,2,3,4,5,6,7 };
	// cout << typeid(x).name() << endl;
	*/
	unordered_set<int> us{ 1,2,3,4,5,6,7,9 };
	/*
	hash 함수 설계 ( 아주 중요하다. )
		-> hash<int>();		// 이름 없는 객체
	
	*/
	/*
	for (int i = 0; i < 10; ++i)
	{
	//	cout << hash<int>().operator()(i) << endl;	// <- 원래 표기 법
		cout << hash<int>()(i) << endl;				 // <- 좀 더 쉬운 표기 법
	}
	*/

	// unordered_set의 메모리 모양을 화면에 출력한다.
	/*
	
	*/
	for (int i = 0; i < us.bucket_count(); ++i) {
		cout << "[" << i << "]";
		if (us.bucket_size(i)) {
			for (auto p = us.begin(i); p != us.end(i); ++p)
				cout << " --> " << *p; 
			
		}
		cout << endl;
	}

}