// list�� sort�� unique
#include <iostream>
#include <list>
#include <string>
#include "String.h"
using namespace std;
template <class T>
void print(string name, T& cont); // container ���� ȭ�����
int main()
{
	list<String> words{ "1", "3", "5", "7", "9", "2", "4", "6", "8", "10", "3", "3" };
	cout << "--- �����̳��� ���� ��� ---" << endl;
	print("words: ", words);

	words.sort([](const String& a, const String& b) {
		return atoi(a.getString().c_str()) < atoi(b.getString().c_str());
		});

	cout << endl << "--- sort ��� ---" << endl;
	print("words: ", words);

	words.unique();
	cout << endl << "--- unique ��� ---" << endl;
	print("words: ", words);
}
template <class T>
void print(string name, T& cont)
{
	cout << name;
	for (auto& n : cont)
		cout << n << ' ';
	cout << endl;
}