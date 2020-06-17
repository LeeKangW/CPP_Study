// 2020. 6. 12 금
//
// 1. 전달되는 반복자에 따라 다르게 구현되는 알고리즘 함수
// 2. String 클래스의 insert 반복자를 구현
//
// 14주 anagram
//
//
//
//

#include"default.h"
#include<set>
#include<algorithm>
#include<iterator>


// 2. constexpr if		- 신식 ( 앞으론 이렇게 하면 된다. )

template<class Iter> 
// typename 으로 자료형임을 알려준다.
// typename iterator_traits<Iter>::difference_type;
int my_distance(Iter b, Iter e) {
	
	// Iter가 반복자이기는 해?
	if (is_base_of_v<input_iterator_tag, iterator_traits<Iter>::iterator_category>)
		cout << "전달된 것은 반복자가 틀림없다" << endl;

	// 반복자가 어떤 종류인지 판단할 수 있어야 한다.
	if constexpr(is_same_v<iterator_traits<Iter>::iterator_category,
		random_access_iterator_tag>) {
		cout << "전달된 반복자는 랜덤 반복자이다" << endl;
		// 만일 반복자가 랜덤액세스반복자라면
		return e - b;
	}
	else {
		int cnt{};
		for (; b != e; ++b)
			++cnt;
		return cnt;
	}
}


int main() {
	int a[123];
	cout << my_distance(begin(a),end(a)) << endl;
	set<int> s{ 1,2,3 };
	cout << my_distance(s.begin(),s.end()) << endl;
}