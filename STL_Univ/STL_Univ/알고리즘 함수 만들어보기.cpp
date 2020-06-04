// --------------------------------------------
// 2020. 06. 01 금
//
// 알고리즘 분류
// 1. 원소를 변경하지 않는 알고리즘
// 2. 원소를 변경하는 알고리즘
// 3. 원소를 정렬하는 알고리즘
// 4. 정렬된 범위에서 동작하는 알고리즘
//
// 1. 알고리즘 함수는 어떻게 작성되나?
// 2. 컨테이너와 알고리즘 함수의 관계?
// 
// 14주 anagram
// --------------------------------------------
#include"default.h"
#include<algorithm>
#include<vector>
#include<set>
#include"String.h"


// 위치 = algorithm ( 범위의 시작, 범위의 끝 );

// [문제] print를 선언하고 정의하라.
// main() 변경 금지. 예시와 같이 출력

template<class Iter>
Iter print(Iter from, Iter to);

template<class Iter,class val>
Iter my_find(Iter from, Iter to, val value);

template<class Iter,class CallableType>
Iter my_find_if(Iter from, Iter to,CallableType f);

int main() 
{
#pragma region print 함수 
	vector<int> v{ 1,3,5,2,4 };

	set<int> s{ v.begin(),v.end() };
	print(v.begin(), v.end()); // 1, 3, 5, 2, 4
	print(s.begin(), s.end()); // 1, 2, 3, 4, 5
#pragma endregion
	
#pragma region  find 함수
	vector<int>::iterator p = my_find(v.begin(), v.end(), 3);
	if (p != v.end())
		cout << *p << "찾았습니다." << endl;
	else
		cout << "없는 원소입니다." << endl;
#pragma endregion

#pragma region find_if 함수
	//v의 원소 중에 홀수를 찾아줘!

	auto p = my_find_if(v.begin(), v.end(), [](int n) {
		return n & 1;
		});

	if (p != v.end())
		cout << "조건에 맞는 원소는" << *p << endl;
	
#pragma endregion


	
	
	
}
template<class Iter>
Iter print(Iter from, Iter to) { // from은 to로 ++로 도달가능하여야 한다.(reachable)
	
	// from 부터 to 까지의 원소값을 직접 출력한다.

	// from이 to에 도달하지 않은 동안이라면
	while(from!=to){
		cout << *from << ' ';
		++from;
	}
	cout << '\n';

	return from;
}
template<class Iter, class val>
Iter my_find(Iter from, Iter to, val value) {

	while (from != to) {
		if (*from == value)
			return from;
		++from;
	}
	return from;
}

template<class Iter,class CallableType>
Iter my_find_if(Iter from, Iter to, CallableType f) {

	while (from != to) {
		if (f(*b))
			return b;
		++b;
	}
	return b;
}
