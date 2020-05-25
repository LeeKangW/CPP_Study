#include<iostream>
#include<unordered_set>
#include<set>
#include"String.h"

using namespace std;

// 템플릿 특수화를 시켜 hash의 string 안의 실제 값으로 hash 함수를 만듦.
template<>
struct hash<String> 
{
	unsigned int operator()(const String& s) const {
		return hash<string>()(s.getString());
	}
};
int main() {
	// unordered를 쓰기 위해선 hash 함수가 필요하다.
	unordered_set<String> us{ "해킹에도","활용될","수","있는","양자","컴퓨팅" };
	
	// 이것보다 빨리 찾아주는 컨테이너는 없다.
	while (true) {
		cout << "찾으실 원소는? ";
		String s;
		cin >> s;

		auto p=us.find(s);
		
		if (p != us.end())
			cout << s << "를 찾았습니다." << endl;
		else
			cout << s << "는 없는 원소입니다." << endl;
	}

	/*
	for (int i = 0; i < us.bucket_count(); ++i) {
		cout << "[" << i << "]";
		if (us.bucket_size(i)) {
			for (auto p = us.begin(i); p != us.end(i); ++p)
				cout << " --> " << *p;

		}
		cout << endl;
	}
	*/
}