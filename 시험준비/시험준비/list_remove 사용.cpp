#include<iostream>
#include<list>
#include<algorithm>
#include"String.h"
using namespace std;


int main() {
	list<String> words{ "������", "����", "�Ÿ��α�", "����", "��..",
"����", "������", "�ñ����" };

	words.erase(remove(words.begin(), words.end(), String{"����"}), words.end());

	for (auto i = words.cbegin(); i != words.cend(); ++i)
		cout << *i << endl;
}
