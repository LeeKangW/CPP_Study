#include"default.h"
#include<map>
#include<fstream>
#include<string>

void input_map(string, map<string, int>&);

int main() {
	cout << "���� ������?";
	string name;
	cin >> name;

	ifstream in(name);
	if (!in)
	{
		cout << name << " - ���� ���� ����" << endl;
		return 0;
	}
	map<string, int> words;

	string str;

	while (in >> str)
	{
	//	words[str]++;		// �� ������ �Լ� ȣ��� �ٲ㺼 ��.
		input_map(str,words);
	}
	for (const auto& [�ܾ�, ����Ƚ��] : words)
		cout << �ܾ� << " - " << ����Ƚ�� << endl;
}

void input_map(string str, map<string, int>& words) {
	
	words[str]++;

	/*
	int i =words[str];
	++i;
	words[str] = i;
	*/
}