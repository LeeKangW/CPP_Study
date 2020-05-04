#include"default.h"
#include<map>
#include<fstream>
#include<string>
#include<algorithm>
#include<vector>

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
		words[str]++; // key�� string�� ã���� value�� int�� ���� ������ŵ�ϴ�
	}
	cout << "�̻��ѳ����Ǿٸ���.txt���� " << words.size() << "������ �ܾ ���Ǿ����ϴ�." << endl;
	
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