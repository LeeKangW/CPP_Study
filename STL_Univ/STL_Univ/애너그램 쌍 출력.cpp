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
	ifstream in("�ܾ��.txt");

	vector<PS> v;
	v.reserve(30'0000);
	copy(istream_iterator<string>{in}, {}, back_inserter(v));

	cout << "���� �ܾ��� �� " << v.size() << endl;

	cout << "���� ��� - " << boolalpha << is_sorted(v.begin(), v.end()) << endl << endl;

	//[����] v[i]�� first �������� ����
	sort(v.begin(), v.end(), [](const PS& a, const PS& b) {
		return a.first < b.first;
		});

	for (int i = 0; i < 1'000; ++i)
		cout << v[i].first << '\t' << v[i].second << endl;
	//[����] �ܾ��.txt �� �ִ� ��� �ֳʱ׷� ���� ȭ�鿡 ����϶�
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
	// ���� ���� ��ġ = v.begin();
	while (true) {
		// �������� = ���� ��ġ�� ���ҿ� ���� ���Ұ� ���� ��ġ�� ã�´�.
				���� = adjacent_find();
		// ���� �������� == ������ ��ġ
		//		break;
		// ������ = �������� �������� �˻��ؼ� ���� �޶����� ��ġ�� ã�´�.
		// 
		// [��������,������) �� anagram ������ �ȴ�.

		// ���� = ��;
	}
	*/

	auto b = v.begin();
	int cnt{};

	/*
#pragma region	�ܾ��.txt�� ��� �ֳʱ׷� �� ���
	//[����] �ܾ��.txt �� �ִ� ��� �ֳʱ׷� ���� 
	// ���� "�ֳʱ׷���.txt"�� ����϶�.
	ofstream out("�ֳʱ׷���.txt");
	while (true) {
		b = adjacent_find(b, v.end(), [](const PS& a,const PS& b) {
				return a.first == b.first;
				});

		if (b == v.end())
			break;

		auto e =find_if_not(b + 1, v.end(), [b](const PS& a) {
				return a.first == b->first;
				});

		// [b,e) ������ anagram�̴�.
		out << '[' << ++cnt << "] ";
		copy(b, e, ostream_iterator<PS>{out, "   "});
		out << endl;

		b = e;
	}
#pragma endregion
*/
	//[����] �ܾ��.txt �� �ִ� ��� �ֳʱ׷� ����  ���� ��������
	// ���� "�ֳʱ׷��� ���� ��������.txt"�� ����϶�.
#pragma region
	ofstream out("�ֳʱ׷��� ���� ��������.txt");
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

	// VS�� ���� �������� ����
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