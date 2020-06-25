/*
constexpr �� 
C++17�� �ͼ��� 
������� boolean ���θ� ������ Ÿ�ӿ� ���� �� �ֵ��� 
if constexpr�� �߰��Ǿ�����,
constexpr lambda ���� �߰��Ǿ���.

condition�� true�� ��쿣 statement-false�� ��������, false�� ��쿣 statement-true�� ��������.
������ �ڵ�� ������ ��󿡼� �ƿ� ���ܰ� �ȴ�.
��ó:[C++17] if constexpr

*/

#include<iostream>
#include<iterator>
#include<set>
#include<vector>
using namespace std;

template<class Iter>
unsigned int my_distance(Iter b, Iter e) {
	if (is_base_of_v<input_iterator_tag, iterator_traits<Iter>::iterator_category>) {
		cout << "�ݺ��� �Դϴ�." << endl;
	}
	if constexpr (is_same_v<random_access_iterator_tag, iterator_traits<Iter>::iterator_category>) {
		cout << "���� �ݺ���" << endl;
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