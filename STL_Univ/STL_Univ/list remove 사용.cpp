#include"default.h"
#include<list>
#include"String.h"

int main() {
	list<String> words{ "������","����","�Ÿ��α�","����","��...",
						"����","������","�ñ����" };
	
	for (auto i = words.cbegin(); i != words.cend(); ++i)
	{
		cout<< *i <<endl;
	}
	// ���⿡�� ������ ��������.

	words.erase(remove(words.begin(), words.end(), String("����")),words.end());

	for (auto i = words.cbegin(); i != words.cend(); ++i)
	{
		cout << *i << endl;
	}

}