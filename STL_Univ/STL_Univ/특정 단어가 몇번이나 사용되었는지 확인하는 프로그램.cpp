#include"default.h"
#include<map>
#include<fstream>
#include<string>

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
	string word;
	while (true)
	{
		cout << "찾는 단어는? ";
		cin >> word;

		//map<string,int>::iterator find_word=words.find(word);
		auto find_word = words.find(word);

		if (find_word != words.end())
			cout << word <<" - "<< find_word->second << endl;
		else
			cout << word << "가 없습니다." << endl;
	}
	

}