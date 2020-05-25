#include<iostream>
#include<unordered_set>
#include<random>
#include<thread>
#include"String.h"
#include"save.h"

using namespace std;

//2020.5.25 ��
//
// unordered_set / unordered_map
//
// unordered associative container
// 1. ������ ����.
// 2. �޸� ������ ��� 
// 3. String�� �� �����̳��� ���ҷ� �ǵ��� �Ϸ���

// hash �Լ��� ���� ������ ã�� �� O(1) �� �ɸ���.

int main() {
	/*	initializer_list<int> x = { 1,2,3,4,5,6,7 };
	// -> Ŭ���� �����ڷ� ���� ��.
	// auto x = { 1,2,3,4,5,6,7 };
	// cout << typeid(x).name() << endl;
	*/
	unordered_set<int> us{ 1,2,3,4,5,6,7,9 };
	/*
	hash �Լ� ���� ( ���� �߿��ϴ�. )
		-> hash<int>();		// �̸� ���� ��ü
	
	*/
	/*
	for (int i = 0; i < 10; ++i)
	{
	//	cout << hash<int>().operator()(i) << endl;	// <- ���� ǥ�� ��
		cout << hash<int>()(i) << endl;				 // <- �� �� ���� ǥ�� ��
	}
	*/

	// unordered_set�� �޸� ����� ȭ�鿡 ����Ѵ�.
	/*
	
	*/
	for (int i = 0; i < us.bucket_count(); ++i) {
		cout << "[" << i << "]";
		if (us.bucket_size(i)) {
			for (auto p = us.begin(i); p != us.end(i); ++p)
				cout << " --> " << *p; 
			
		}
		cout << endl;
	}

}