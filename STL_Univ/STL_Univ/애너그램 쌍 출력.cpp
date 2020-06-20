#include<vector>
#include<fstream>
#include<algorithm>
#include<iterator>
#include<set>
#include<iostream>
using namespace std;

struct PS : pair<string, string> {
	PS(string s) : pair(s, s) {
		sort(first.begin(), first.end());
	}
	operator string() {
		return second;
	}
};
ostream& operator<<(ostream& os, const PS& p) {
	os << p.second;
	return os;
}

int main() {
	ifstream in("단어들.txt");

	vector<PS> v;
	v.reserve(30'0000);
	copy(istream_iterator<string>{in}, {}, back_inserter(v));

	cout << "읽은 단어의 수 " << v.size() << endl;

	cout << "정렬 결과 - " << boolalpha << is_sorted(v.begin(), v.end()) << endl << endl;

	//[문제] v[i]를 first 오름차순 정렬
	sort(v.begin(), v.end(), [](const PS& a, const PS& b) {
		return a.first < b.first;
		});

	for (int i = 0; i < 1'000; ++i)
		cout << v[i].first << '\t' << v[i].second << endl;
	//[문제] 단어들.txt 에 있는 모든 애너그램 쌍을 화면에 출력하라
	/*
		aaaabchhir      bhaiachara
		aaaabchhiry     bhaiyachara
		aaaabchiillnoprt        palliobranchiata
b		aaaabchiimnoprrst       marsipobranchiata
		aaaabchiimnoprrst       basiparachromatin
e		aaaabchilnprr   parabranchial
		aaaabchinooprrt aporobranchiata
	*/
	/*
	// 현재 시작 위치 = v.begin();
	while (true) {
		// 구간시작 = 현재 위치의 원소와 다음 원소가 같은 위치를 찾는다.
				시작 = adjacent_find();
		// 만일 구간시작 == 마지막 위치
		//		break;
		// 구간끝 = 구간시작 다음부터 검사해서 값이 달라지는 위치를 찾는다.
		// 
		// [구간시작,구간끝) 은 anagram 구간이 된다.

		// 시작 = 끝;
	}
	*/

	auto b = v.begin();
	int cnt{};

	/*
#pragma region	단어들.txt에 모든 애너그램 쌍 출력
	//[문제] 단어들.txt 에 있는 모든 애너그램 쌍을 
	// 파일 "애너그램쌍.txt"에 출력하라.
	ofstream out("애너그램쌍.txt");
	while (true) {
		b = adjacent_find(b, v.end(), [](const PS& a,const PS& b) {
				return a.first == b.first;
				});

		if (b == v.end())
			break;

		auto e =find_if_not(b + 1, v.end(), [b](const PS& a) {
				return a.first == b->first;
				});

		// [b,e) 구간은 anagram이다.
		out << '[' << ++cnt << "] ";
		copy(b, e, ostream_iterator<PS>{out, "   "});
		out << endl;

		b = e;
	}
#pragma endregion
*/
	//[문제] 단어들.txt 에 있는 모든 애너그램 쌍을  개수 내림차순
	// 파일 "애너그램쌍 개수 내림차순.txt"에 출력하라.
#pragma region
	ofstream out("애너그램쌍 개수 내림차순.txt");
	vector< set<string> > vs;
	while (true) {
		b = adjacent_find(b, v.end(), [](const PS& a, const PS& b) {
			return a.first == b.first;
			});

		if (b == v.end())
			break;

		auto e = find_if_not(b + 1, v.end(), [b](const PS& a) {
			return a.first == b->first;
			});

		set<string> s{ b,e };

		vs.push_back(s);
		b = e;
	}

	// VS를 개수 기준으로 정렬
	sort(vs.begin(), vs.end(), [](const set<string>& a, const set<string>& b) {
		return a.size() > b.size();
		});
	
	for (int i = 0; i < vs.size(); ++i) {
		out << "[" << i + 1 << "] (" << vs[i].size() << ") - ";
		copy(vs[i].begin(), vs[i].end(), ostream_iterator<string>{out, "  "});
		out << endl;
	}
#pragma endregion
}