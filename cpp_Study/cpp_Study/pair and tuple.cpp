#include<iostream>
#include<vector>
#include<tuple>

using namespace std;

int main()
{
	pair<int, string>p(2,"생성과 동시에 초기화");
	p = make_pair(100, "GM");
	auto [점수, 그룹이름] = p;

	cout << 점수 << "," << 그룹이름 << endl;
	// cout << p.first << "," << p.second << endl;

	tuple<int, string, float> t;
	t = make_tuple(3, "튜플스트링", 4.f);

	cout << get<0>(t) << endl;

	vector<pair<int, string>> v;
	v.push_back(make_pair(3, "스트링"));


}