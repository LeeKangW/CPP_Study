#include"default.h"
#include<array>
#include<algorithm>
#include"String.h"

int main()
{
	array<String, 16> words{ "Anger", "as", "Japanese", "Prime", "Minister offers", "two",
	"cloth", "masks", "per", "family", "while", "refusing", "to", "declare",
	"coronavirus", "emergency" };

	cout << "�����ϱ� ��" << endl;
	for (int i = 0; i < words.size(); ++i)
		cout << words[i] << " ";
	cout << endl << endl;

		sort(&words[0],&(words[0])+1, [](const String& a, const String& b) {
			a.getString() < b.getString();
			});

	cout << "������ ���" << endl;

	for (int i = 0; i < words.size(); ++i)
		cout << words[i] << " ";

	cout << endl;
}