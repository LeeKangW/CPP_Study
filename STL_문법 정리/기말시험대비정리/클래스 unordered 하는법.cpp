#include<iostream>
#include<unordered_set>
#include"String.h"

using namespace std;

template<>
struct hash<String> {
	unsigned int operator()(const String& s)const {
		return hash<string>()(s.getString());
	}
};

int main() {
	unordered_set<String> d{ "코로나","이런","제발멈추길" };

	for (int i = 0; i < d.bucket_count(); ++i) {
		cout << "[" << i << "] ";
		if (d.bucket_size(i)) {
			for (auto j = d.begin(i); j != d.end(i); ++j) {
				cout << *j << "-->";
			}
		}
		cout << endl;
	}
}