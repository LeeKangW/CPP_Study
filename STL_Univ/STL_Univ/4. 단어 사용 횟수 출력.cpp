#include"default.h"
#include<map>
#include<fstream>
#include<string>

void input_map(string, map<string, int>&);

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
	//	words[str]++;		// 이 문장을 함수 호출로 바꿔볼 것.
		input_map(str,words);
	}
	for (const auto& [단어, 출현횟수] : words)
		cout << 단어 << " - " << 출현횟수 << endl;
}

void input_map(string str, map<string, int>& words) {
	
	words[str]++;

	/*
	int i =words[str];
	++i;
	words[str] = i;
	*/
}