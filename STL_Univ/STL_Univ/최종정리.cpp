#include<iostream>
#include<algorithm>
#include<iterator>
using namespace std;

class Dog {
public:
	Dog() {
		new int;		// 생성 시 자원 확보
	}
	// 생성 시 new int와 같은 작업을 했으면, 아래의 행동을 해줘야 한다.
	~Dog() {}
	Dog(const Dog&) {}
	Dog& operator=(const Dog&);
	// 이동
	// 이동할당
};
class B {
public:
	void operator() () {}
};

template<class Iter,class Out>

Out my_copy(Iter b, Iter e, Out o) {

	// T가 반복자인지 판단
	is_base_of_v<output_iterator_tag,iterator_trait<Iter>::iterator_category>

	return o;
}
int main() {

#pragma region syntactic sugar
	int a[]{ 1,2,3 };
	cout << a[0] << endl; // a[0] -> syntactic sugar
	cout << *(a + 0) << endl; // a[0] -> syntactic sugar



	for (int n : a) // syntactic sugar
		cout << n << endl;
#pragma endregion

#pragma region smart pointer

	unique_ptr<int, > p;	// deleter를 할 줄 알야 한다. ( 배열로 만들 시 )
#pragma endregion

#pragma region 호출 가능 타입
	int n;
	// n이 호출 가능하니??
	B b;
	b();

	// n이 호출이 가능하다면, n(); // 이걸 할 수 있으면 호출가능타입이다.

	// Q. 호출 가능 타입이 뭔가?  A : 호출이 가능한 타입
	// -> () 로 호출이 가능하면 된다.

#pragma endregion

// 연관 컨테이너
	// hash 함수 -> unordered -> 검색 속도가 가장 빠르다.

#pragma region 반복자 
	// Q : 반복자란?
	// A : 반복자는 반복자처럼 행동할 수 있는 것. / 포인터를 추상화 한 것.
	
	
	// copy(begin(a), end(a), ostream_iterator<int>{cout, "\n"});
	my_copy(begin(a), end(a), ostream_iterator<int>{cout, "\n"});
#pragma endregion

#pragma region 반복자 어댑터
	// 삽입 반복자, 역방향 반복자 등

#pragma endregion


}