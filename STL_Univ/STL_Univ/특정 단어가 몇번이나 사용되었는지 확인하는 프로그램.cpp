#include"default.h"
#include<map>
#include<fstream>
#include<string>

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
	string word;
	while (true)
	{
		cout << "ã�� �ܾ��? ";
		cin >> word;

		//map<string,int>::iterator find_word=words.find(word);
		auto find_word = words.find(word);

		if (find_word != words.end())
			cout << word <<" - "<< find_word->second << endl;
		else
			cout << word << "�� �����ϴ�." << endl;
	}
	

}