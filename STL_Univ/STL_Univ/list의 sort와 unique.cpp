#include"default.h"
#include<list>
#include<string>
#include"String.h"

template<class T>
void print(string, T&); // container ���� ȭ�� ���

int main() {
	list<String> words{ "1","3","5","7","9","2","4","6","8","10","3","3" };

	cout << "---- �����̳� ���� ��� -----" << endl;
	print("words: ", words);

	//words�� �����Ѵ�.
	words.sort([](const String& a, const String& b) {
		return a.getString() < b.getString();
		});

	cout << endl << "--- sort ��� ---" << endl;
	print("words : ", words);

	//������ �ߺ����Ҹ� �����Ѵ�.
	words.unique();

	cout << endl << "--- unique ��� ---" << endl;
	print("words: ", words);

}
template<class T>
void print(string name, T& cont) {
	cout << name;
	for (auto& n : cont)
		cout << n << ' ';
	cout << endl;
}