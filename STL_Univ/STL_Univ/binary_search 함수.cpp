#include"default.h"
#include<string>
#include<vector>
#include<fstream>
#include<iterator>
#include<algorithm>

// 이진 탐색 - 정렬된 데이터가 있다면 이렇게 찾아야 겠다.

// "이상한나라의앨리스.txt"를 읽어서 설명

int main() {
	
	ifstream in("이상한나라의앨리스.txt");
	
	vector<string> v{ istream_iterator<string>{in},{} };		// {} -> EOF 를 뜻 함.

	cout << v.size() <<"단어를 읽었다."<< endl;

	sort(v.begin(), v.end());

	// [문제] 찾는 단어가 있다면 어디에 있는지 몇개나 있는지 
	// 알려주는 프로그램을 만들어라.
	// [같은 문제] 정렬된 상태를 깨뜨리지 않고, word를 집어넣을 수 있는
	// 위치를 찾아라. -> equal_range 함수

	while (true) {
		cout << endl << " 단어를 입력하세요 : ";
		string word;
		cin >> word;

		auto [로우,하이] = equal_range(v.begin(), v.end(), word);

		if (로우 == 하이)
			cout << word << "는 사전에 없는 단어입니다." << endl;
		else
			cout << 하이 - 로우 << "개의 " << word << "가 있습니다." << endl;

		copy(로우 - 1, 하이 + 1, ostream_iterator<string>(cout, " "));
		/*
		// auto p  = find(v.begin(), v.end(), word);
		auto p = binary_search(v.begin(), v.end(), word); // 정렬된 상태에서는 이진 탐색으로 찾아야 한다.
		if (p)
			cout << word << "를 찾았습니다." << endl;
		else
			cout << "없는 단어입니다." << endl;
		*/
	}
}