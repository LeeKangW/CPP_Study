#include"default.h"
#include"String.h"
#include<vector>
#include<list>

// declaration
//void print(String::iterator b, String::iterator e);
template<class T>
void print(T b, T e);

int main() {
	String str{ "The quick brown fox jumps over the lazy dog" };

	vector<char> v{ str.begin(),str.end() };
	list<char> l{ v.begin(),v.end() };
	print(str.begin(), str.end());
	// ���ø����� �ϸ� ����.
	print(v.begin(), v.end());
	print(l.begin(), l.end());
	
}

/*
//definition
void print(String::iterator b, String::iterator e) {
	while (b != e) {
		cout << *b << ' ';
		++b;
	}
	cout << endl;
}
*/

template<class T>
void print(T b, T e) {
	while (b != e) {
		cout << *b << ' ';
		++b;
	}
	cout << endl;
}