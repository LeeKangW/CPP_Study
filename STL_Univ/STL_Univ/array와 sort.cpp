#include"default.h"
#include<array>
#include<algorithm>
#include"String.h"

int main() {

	array<String, 5>words{ "New","York","schools","dropping","Zoom" };

	// ���⿡ �� ���� �ڵ带 �����.
	sort(words.begin(), words.end(), [](const String& a, const String& b) {
		return a.size() < b.size();
		});

	cout << "������ ��� " << endl;
	for (int i = 0; i < words.size(); ++i)
		cout << words[i] << endl;
}