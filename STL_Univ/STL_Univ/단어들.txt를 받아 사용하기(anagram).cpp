#include"default.h"
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>

// anagram 이란 철자 순서를 바꿔보는 것
// 입력 : dog
// 출력 : dog의 애너그램 쌍은 dog, god 입니다.
// dog --> 0
// dgo	   X
// odg     X
// ogd     X
// gdo     X
// god     O

/*
찾기 위해서 해야 할 것들

1. 찾을 단어가 존재하는지 확인.
2. 애너그램이 있는지... -> 순열로 찾는다. next_permutation( ) 사용
*/

struct PS : pair<string,string> {
	PS(string s) : pair(s, s) {
		sort(first.begin(), first.end());
	}
};

int main() {
	/*
	nth_element(v.begin(), v.begin() + 10, v.end(), [](const string& a, const string& b) {
		return a.size() > b.size();
		});
	for (int i = 0; i < 10; ++i)
		cout << v[i] << endl;
	
		 긴 단어들....
		dichlorodiphenyltrichloroethane
		cyclotrimethylenetrinitramine
		trinitrophenylmethylnitramine
		hydroxydehydrocorticosterone
		antidisestablishmentarianism
		electroencephalographically
		hydroxydesoxycorticosterone
		microspectrophotometrically
		antidisestablishmentarian
		regeneratoryregeneratress
	*/
#pragma region 단어가 길어지면 시간이 오래걸리기에 정답이 아님.
	/*

	ifstream in("단어들.txt");
	if (!in)
	{
		cout << "파일이 존재하지 않습니다." << endl;
	}

	vector<string> v;
	v.reserve(30'0000);
	string s;

	while (in >> s) {
		v.push_back(s);
	}
	cout <<"읽은 단어의 수 "<< v.size() << endl;

	cout << "정렬 결과 - " << boolalpha << is_sorted(v.begin(), v.end()) << endl;


	while (true)
	{
		cout << "찾을 단어를 입력하세요: ";
		string word;
		cin >> word;

		// [문제] word가 사전에 있는지 없는지 출력하라.

		auto b = binary_search(v.begin(), v.end(), word);
		if (!b) {
			cout << "사전에 없는 단어입니다." << endl;
			continue;
		}

		// [문제] word의 anagram을 모두 출력하라.
		// 단어가 길어지면 찾는데 너무 오래 걸린다.
		sort(word.begin(), word.end());
		do {
			auto b = binary_search(v.begin(), v.end(), word);
			if (b) {
				cout << word << endl;
			}
		} while (next_permutation(word.begin(), word.end()));

	}
	*/
#pragma endregion

#pragma region 정답
	// 단어들을 다 정렬해버리면 같은 쌍을 구할 수 있다.
	// dog -> dgo
	// god -> dgo

	ifstream in("단어들.txt");
	if (!in)
	{
		cout << "파일이 존재하지 않습니다." << endl;
	}

	// vecotr < pair<정렬string,원본string> v;
	vector<PS> v;
	v.reserve(30'0000);
	string s;

	while (in >> s)
		v.emplace_back(s);

	cout << "읽은 단어의 수 " << v.size() << endl;

	cout << "정렬 결과 - " << boolalpha << is_sorted(v.begin(), v.end()) << endl<<endl;

	//[문제] v[i]를 first 오름차순 정렬
	sort(v.begin(), v.end(), [](const PS& a, const PS& b) {
		return a.first < b.first;
		});

	//[문제] 찾는 단어의 anagram을 최고 빨리 찾아주자!
	while (true) {
		string word;
		cout << "찾을 단어? ";
		cin >> word;

		auto [하한, 상한] = equal_range(v.begin(), v.end(),PS(word) ,
			[](const PS& a, const PS& b) {
				return a.first < b.first;
			});

		if (하한 == 상한) {
			cout << "없는 단어입니다." << endl;
			continue;
		}
		for (auto i = 하한; i < 상한; ++i) {
			cout << i->second << "   ";
		}
		cout << endl;
	}
	
#pragma endregion

		/*
		정렬이 되어 있기 때문에 이 방법말고 이진탐색을 써야 한다. 
		auto it =find(v.begin(), v.end(), word);
		
		if (it != v.end())
			cout << word << "는 존재합니다." << endl;
		else
			cout << word << "존재하지 않습니다." << endl;
		*/
	
}