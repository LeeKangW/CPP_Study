// 2020. 6. 12 ��
//
// 1. ���޵Ǵ� �ݺ��ڿ� ���� �ٸ��� �����Ǵ� �˰��� �Լ�
// 2. String Ŭ������ insert �ݺ��ڸ� ����
//
// 14�� anagram
//
//
//
//

#include"default.h"
#include<set>
#include<algorithm>
#include<iterator>


// 2. constexpr if		- �Ž� ( ������ �̷��� �ϸ� �ȴ�. )

template<class Iter> 
// typename ���� �ڷ������� �˷��ش�.
// typename iterator_traits<Iter>::difference_type;
int my_distance(Iter b, Iter e) {
	
	// Iter�� �ݺ����̱�� ��?
	if (is_base_of_v<input_iterator_tag, iterator_traits<Iter>::iterator_category>)
		cout << "���޵� ���� �ݺ��ڰ� Ʋ������" << endl;

	// �ݺ��ڰ� � �������� �Ǵ��� �� �־�� �Ѵ�.
	if constexpr(is_same_v<iterator_traits<Iter>::iterator_category,
		random_access_iterator_tag>) {
		cout << "���޵� �ݺ��ڴ� ���� �ݺ����̴�" << endl;
		// ���� �ݺ��ڰ� �����׼����ݺ��ڶ��
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