#include<iostream>
#include<vector>
#include<tuple>

using namespace std;

int main()
{
	pair<int, string>p(2,"������ ���ÿ� �ʱ�ȭ");
	p = make_pair(100, "GM");
	auto [����, �׷��̸�] = p;

	cout << ���� << "," << �׷��̸� << endl;
	// cout << p.first << "," << p.second << endl;

	tuple<int, string, float> t;
	t = make_tuple(3, "Ʃ�ý�Ʈ��", 4.f);

	cout << get<0>(t) << endl;

	vector<pair<int, string>> v;
	v.push_back(make_pair(3, "��Ʈ��"));


}