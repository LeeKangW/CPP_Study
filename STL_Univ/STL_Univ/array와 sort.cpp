#include"default.h"
#include<array>
#include<algorithm>
#include"String.h"

int main() {

	array<String, 5>words{ "New","York","schools","dropping","Zoom" };

	// 여기에 들어갈 정렬 코드를 적어라.
	sort(words.begin(), words.end(), [](const String& a, const String& b) {
		return a.size() < b.size();
		});

	cout << "정렬한 결과 " << endl;
	for (int i = 0; i < words.size(); ++i)
		cout << words[i] << endl;
}