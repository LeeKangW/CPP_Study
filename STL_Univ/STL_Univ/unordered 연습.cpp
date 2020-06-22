#include<iostream>
#include<string>
#include<unordered_set>
#include"String.h"
using namespace std;

template<>
struct hash<String> {
	unsigned int operator()(const String& s) const{
		return hash<string>()(s.getString());
	}
};
int main() {
	unordered_set<String> s{ "우리","이름","오키오키" };

	for (int i = 0; i < s.bucket_count(); ++i) {
		cout << "[" << i << "]";
		if (s.bucket_size(i)) {
			for (auto it = s.begin(i); it != s.end(i); ++it)
				cout << *it << "-->";
		}
		cout << endl;
	}
}