#include"default.h"
#include<set>
#include<iterator>

int main() {
	cout << "뭐든지 입력하세요. 끝내려면 Ctrl+z를 누르세요" << endl << endl;

	multiset<string> ms{ istream_iterator<string>(cin),istream_iterator<string>() };

	cout << endl << "오름차순 정렬한 결과입니다." << endl << endl;
	for (const string& s : ms)
		cout << s << endl;
}