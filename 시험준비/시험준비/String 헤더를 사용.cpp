#include<iostream>
#include<array>
#include<algorithm>
#include"String.h"
using namespace std;


int main() {

	array<String, 16> words{ "Anger", "as", "Japanese", "Prime", "Minister offers", "two",
"cloth", "masks", "per", "family", "while", "refusing", "to", "declare",
"coronavirus", "emergency" };
	cout << "�����ϱ� ��" << endl;
	for (int i = 0; i < words.size(); ++i)
		cout << words[i] << " ";
	cout << endl << endl;
	// ���⿡ �� ���� �ڵ带 �����.
	
	for (String& word : words) {
		sort(&word[0], &word[word.size()], [](const char& a, const char& b) {
			return a < b;
			});
	}

	cout << "������ ���" << endl;
	for (int i = 0; i < words.size(); ++i)
		cout << words[i] << " ";
	cout << endl;

}