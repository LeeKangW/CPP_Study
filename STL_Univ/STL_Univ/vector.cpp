#include"default.h"
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>


int main() {
	vector<string> v;

	string s;

	cout << " 단어를 마음껏 입력하세요. 끝내시려면 Ctrl-z를 입력하세요." << endl;

	while (cin >> s) {
		v.push_back(s);
	}

	cout << "입력이 끝났습니다." << endl;

	sort(v.begin(), v.end());

	cout << "정렬 결괄르 출력합니다." << endl;

	for (auto&& s : v)
		cout << s << '\t';
	cout << endl;

}