#include"default.h"
#include<list>
#include<string>
#include"String.h"

template<class Iter>
void print(string, Iter&); // container 내용 화면 출력

int main() {
	list<String> words{ "1","3","5","7","9","2","4","6","8","10","3","3" };

	cout << "---- 컨테이너 원소 출력 -----" << endl;
	print("words: ", words);

	//words를 정렬한다.
	words.sort([](const String& a, const String& b) {
		return a.getString() < b.getString();
		});

	cout << endl << "--- sort 결과 ---" << endl;
	print("words : ", words);

	//인접한 중복원소를 제거한다.
	words.unique();

	cout << endl << "--- unique 결과 ---" << endl;
	print("words: ", words);

}
template<class Iter>
void print(string name, Iter& cont) {
	cout << name;
	for (auto& n : cont)
		cout << n << ' ';
	cout << endl;
}