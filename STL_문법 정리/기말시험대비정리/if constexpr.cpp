/*
constexpr 은 
C++17에 와서는 
상수식의 boolean 여부를 컴파일 타임에 평가할 수 있도록 
if constexpr이 추가되었으며,
constexpr lambda 역시 추가되었다.

condition이 true일 경우엔 statement-false가 버려지며, false일 경우엔 statement-true가 버려진다.
버려진 코드는 컴파일 대상에서 아예 제외가 된다.
출처:[C++17] if constexpr

*/

#include<iostream>
#include<iterator>
#include<set>
#include<vector>
using namespace std;

template<class Iter>
unsigned int my_distance(Iter b, Iter e) {
	if (is_base_of_v<input_iterator_tag, iterator_traits<Iter>::iterator_category>) {
		cout << "반복자 입니다." << endl;
	}
	if constexpr (is_same_v<random_access_iterator_tag, iterator_traits<Iter>::iterator_category>) {
		cout << "랜덤 반복자" << endl;
		return e - b;
	}
	else {
		unsigned int cnt{};
		for (; b != e; ++b)
			++cnt;
		return cnt;
	}
}
int main() {
	set<int> s{ 1,2,3,4,5 };
	vector<int> v{ 1,2,3,4,5 };
	 cout << my_distance(s.begin(), s.end()) << endl;
	 cout << my_distance(v.begin(), v.end()) << endl;
}