// --------------------------------------------
// 2020. 06. 01 ��
//
// �˰��� �з�
// 1. ���Ҹ� �������� �ʴ� �˰���
// 2. ���Ҹ� �����ϴ� �˰���
// 3. ���Ҹ� �����ϴ� �˰���
// 4. ���ĵ� �������� �����ϴ� �˰���
//
// 1. �˰��� �Լ��� ��� �ۼ��ǳ�?
// 2. �����̳ʿ� �˰��� �Լ��� ����?
// 
// 14�� anagram
// --------------------------------------------
#include"default.h"
#include<algorithm>
#include<vector>
#include<set>
#include"String.h"


// ��ġ = algorithm ( ������ ����, ������ �� );

// [����] print�� �����ϰ� �����϶�.
// main() ���� ����. ���ÿ� ���� ���

template<class Iter>
Iter print(Iter from, Iter to);

template<class Iter,class val>
Iter my_find(Iter from, Iter to, val value);

template<class Iter,class CallableType>
Iter my_find_if(Iter from, Iter to,CallableType f);

int main() 
{
#pragma region print �Լ� 
	vector<int> v{ 1,3,5,2,4 };

	set<int> s{ v.begin(),v.end() };
	print(v.begin(), v.end()); // 1, 3, 5, 2, 4
	print(s.begin(), s.end()); // 1, 2, 3, 4, 5
#pragma endregion
	
#pragma region  find �Լ�
	vector<int>::iterator p = my_find(v.begin(), v.end(), 3);
	if (p != v.end())
		cout << *p << "ã�ҽ��ϴ�." << endl;
	else
		cout << "���� �����Դϴ�." << endl;
#pragma endregion

#pragma region find_if �Լ�
	//v�� ���� �߿� Ȧ���� ã����!

	auto p = my_find_if(v.begin(), v.end(), [](int n) {
		return n & 1;
		});

	if (p != v.end())
		cout << "���ǿ� �´� ���Ҵ�" << *p << endl;
	
#pragma endregion


	
	
	
}
template<class Iter>
Iter print(Iter from, Iter to) { // from�� to�� ++�� ���ް����Ͽ��� �Ѵ�.(reachable)
	
	// from ���� to ������ ���Ұ��� ���� ����Ѵ�.

	// from�� to�� �������� ���� �����̶��
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
