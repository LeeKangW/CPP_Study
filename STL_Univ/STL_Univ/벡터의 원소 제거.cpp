#include"default.h"
#include<vector>
#include<algorithm>

//#define Q1

int main() {
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	//[����]�� �ذ��ϴ� �ڵ带 �ۼ�.

#ifdef Q1 // ���� 3 ����
	/*
	auto i = remove(v.begin(), v.end(), 3);
	v.erase(i);
	*/
	v.erase(remove(v.begin(), v.end(), 3));

#endif
#ifndef Q1 // Ȧ�� ����
	/*
	v.erase(remove_if(v.begin(), v.end(), [](int i) {
		return i & 1;
		}),v.end());
		*/
		// C++ 20 ���
	erase_if(v, [](int n) {return n & 1; });
#endif
	for (int n : v) // int�� ��� ���糪 const &�� ���̾���.
		cout << n << ' '; 
	cout << endl;
}