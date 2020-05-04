#include"default.h"
#include<map>
#include<fstream>
#include<string>
#include<algorithm>
#include<vector>

int main() {
	cout << "읽을 파일은?";
	string name;
	cin >> name;

	ifstream in(name);
	if (!in)
	{
		cout << name << " - 파일 열기 실패" << endl;
		return 0;
	}
	map<string, int> words;

	string str;

	while (in >> str)
	{
		words[str]++; // key인 string을 찾으면 value인 int의 값을 증가시킵니다
	}
	cout << "이상한나라의앨리스.txt에는 " << words.size() << "가지의 단어가 사용되었습니다." << endl;
	
	vector<pair<string, int>> v;

	/*
	for (const pair<string,int>& t : words)
		v.push_back(t);
	*/

	for (const auto& t : words)
		v.push_back(t);

	sort(v.begin(), v.end(), [](pair<string, int> a, pair<string, int> b) {
		return a.second > b.second;
		});
	/*
	for (const pair<string,int>& t : v)
		cout << t.first << " - " << t.second << endl;
	*/
	for (const auto& t : v)
		cout << t.first << " - " << t.second << endl;
}