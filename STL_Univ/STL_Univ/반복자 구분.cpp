#include<iostream>
#include<functional>
#include<iterator>
#include<set>
using namespace std;

void custom(int* p)
{
	cout << "스마트포인터" << endl;
	delete[] p;
}

template<class Iter>
size_t my_distance(Iter b, Iter e) {
	// 랜덤 반복자라면 e-b 로도 구할 수 있다.

	if (is_base_of_v<input_iterator_tag, iterator_traits<Iter>::iterator_category>) {
		if constexpr (is_same_v<random_access_iterator_tag, iterator_traits<Iter>::iterator_category>)
		{
			return e - b;
		}
		else {
			int cnt{};
			for (; b != e; ++b)
				++cnt;
			return cnt;
		}
	}
}

int main() {
#pragma region if constexpr
	int a[123];
	cout << my_distance(begin(a), end(a)) << endl;
	set<int> s{ 1,2,3 };
	cout << my_distance(s.begin(), s.end()) << endl;
#pragma endregion

	

	
}