// list의 sort와 unique
#include <iostream>
#include <list>
#include <string>
#include "String.h"
using namespace std;
template <class T>
void print(string name, T& cont); // container 내용 화면출력
int main()
{
	list<String> words{ "1", "3", "5", "7", "9", "2", "4", "6", "8", "10", "3", "3" };
	cout << "--- 컨테이너의 원소 출력 ---" << endl;
	print("words: ", words);

	words.sort([](const String& a, const String& b) {
		return atoi(a.getString().c_str()) < atoi(b.getString().c_str());
		});

	cout << endl << "--- sort 결과 ---" << endl;
	print("words: ", words);

	words.unique();
	cout << endl << "--- unique 결과 ---" << endl;
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