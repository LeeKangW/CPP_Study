#include<iostream>
#include<list>
#include<algorithm>
#include"String.h"
using namespace std;


int main() {
	list<String> words{ "공무원", "고강도", "거리두기", "한주", "더..",
"교실", "수업은", "시기상조" };

	words.erase(remove(words.begin(), words.end(), String{"고강도"}), words.end());

	for (auto i = words.cbegin(); i != words.cend(); ++i)
		cout << *i << endl;
}
