#include"default.h"
#include<string>
#include<vector>
#include<iterator>
#include <algorithm>

int main() {
	cout << "단어를 마음껏 입력하세요. 끝내시려면 Ctrl-z를 입력하세요" << endl;

	vector<string> v{ istream_iterator<string>(cin),istream_iterator<string>() };

	sort(begin(v), end(v));
	copy(begin(v), end(v), ostream_iterator<string>(cout, "\t"));
}