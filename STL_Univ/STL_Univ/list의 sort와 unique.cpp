#include"default.h"
#include<list>
#include<string>
#include"String.h"

template<class Iter>
void print(string, Iter&); // container ���� ȭ�� ���

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
template<class Iter>
void print(string name, Iter& cont) {
	cout << name;
	for (auto& n : cont)
		cout << n << ' ';
	cout << endl;
}