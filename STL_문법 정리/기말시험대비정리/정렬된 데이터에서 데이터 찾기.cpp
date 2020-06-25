#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<string>
using namespace std;

class Dog {
	string str{};

public:
	Dog(string s) :str{ s } {}
	
	string_view GetString() const { return str; }
};
int main() {
	vector<int> v{ 1,2,3,4,5 };
	vector<int> v2{ 1,3,3,3,5,5,5,8,8 };
	vector<Dog> v_dog;
	v_dog.emplace_back("이런");
	v_dog.emplace_back("클래스도");
	v_dog.emplace_back("가능하겠지");

	list<int> l{ v.begin(),v.end() };

	if (is_sorted(v.begin(), v.end())) {
#pragma region binary_search
		// 데이터가 있는지 없는지 찾기는 binary_search( )
		cout << "======= binary_search =======" << endl << endl;
		bool b = binary_search(v.begin(), v.end(), 3);
		if (b)
			cout << "데이터 있음" << endl;
		else
			cout << "데이터 없음" << endl;

		cout << "=====================" << endl << endl;
#pragma endregion
	}
#pragma region lower_bound
	// lower_bound 는 
	// 찾으려는
	// 데이터가 있다면, 데이터의 위치를 반복자로 반환해주고
	// 데이터가 없다면, 데이터보다 큰 가장 작은 값을 찾는다.

	cout << "======= lower_bound =======" << endl << endl;
	auto it = lower_bound(v2.begin(), v2.end(), 3);
	cout << "lower_bound - "<< *it << endl;
	cout << "=====================" << endl << endl;
#pragma endregion
#pragma region upper_bound
	// upper_bound 는
	// 찾으려는
	// 데이터가 있다면, 데이터 값을 초과하는 가장 첫 번 째 원소의 위치를 반환 ( Ex. 3, 3, 3, 5 일 때, 3을 찾으면 5가 나옴 )
	// 데이터가 없으면, 정렬 기준 다음 데이터 위치를 반환한다.
	cout << "======= upper_bound =======" << endl << endl;
	auto it2 = upper_bound(v2.begin(), v2.end(), 3);
	cout << "upper_bound - " << *it2 << endl;
	cout << "=====================" << endl << endl;
#pragma endregion
	
#pragma region equal_range
	// [같은 문제] 정렬된 상태를 깨뜨리지 않고, 4를 넣을 위치를 찾아라.
	// 위치를 찾아라. -> equal_range 함수
	// equal_range는 lower_bound(), upper_bound() 결과를 쌍으로 던져준다.

	cout << "======= equal_range =======" << endl <<endl;
	

	auto [상한,하한] = equal_range(v2.begin(), v2.end(), 3);
	
	if (상한 == 하한) {
		cout << "중복되는 값이 없습니다." << endl;
		cout << "상한 값 - " << *상한 << " 하한 값 - "<< *하한 <<endl;
	}
	else {
		cout << "중복되는 값이 있습니다." << endl;
		cout << "상한 값 - " << *상한 << " 하한 값 - " << *하한 << endl;
	}
	cout << "=====================" << endl << endl;
#pragma endregion

	
}