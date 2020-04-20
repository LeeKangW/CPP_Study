#include"default.h"
#include<list>
#include"String.h"

int main() {
	list<String> words{ "공무원","고강도","거리두기","한주","더...",
						"교실","수업은","시기상조" };
	
	for (auto i = words.cbegin(); i != words.cend(); ++i)
	{
		cout<< *i <<endl;
	}
	// 여기에서 고강도를 제거하자.

	words.erase(remove(words.begin(), words.end(), String("고강도")),words.end());

	for (auto i = words.cbegin(); i != words.cend(); ++i)
	{
		cout << *i << endl;
	}

}