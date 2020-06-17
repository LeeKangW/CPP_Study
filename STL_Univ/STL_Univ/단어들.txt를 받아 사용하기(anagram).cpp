#include"default.h"
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>

// anagram �̶� ö�� ������ �ٲ㺸�� ��
// �Է� : dog
// ��� : dog�� �ֳʱ׷� ���� dog, god �Դϴ�.
// dog --> 0
// dgo	   X
// odg     X
// ogd     X
// gdo     X
// god     O

/*
ã�� ���ؼ� �ؾ� �� �͵�

1. ã�� �ܾ �����ϴ��� Ȯ��.
2. �ֳʱ׷��� �ִ���... -> ������ ã�´�. next_permutation( ) ���
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
	
		 �� �ܾ��....
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
#pragma region �ܾ ������� �ð��� �����ɸ��⿡ ������ �ƴ�.
	/*

	ifstream in("�ܾ��.txt");
	if (!in)
	{
		cout << "������ �������� �ʽ��ϴ�." << endl;
	}

	vector<string> v;
	v.reserve(30'0000);
	string s;

	while (in >> s) {
		v.push_back(s);
	}
	cout <<"���� �ܾ��� �� "<< v.size() << endl;

	cout << "���� ��� - " << boolalpha << is_sorted(v.begin(), v.end()) << endl;


	while (true)
	{
		cout << "ã�� �ܾ �Է��ϼ���: ";
		string word;
		cin >> word;

		// [����] word�� ������ �ִ��� ������ ����϶�.

		auto b = binary_search(v.begin(), v.end(), word);
		if (!b) {
			cout << "������ ���� �ܾ��Դϴ�." << endl;
			continue;
		}

		// [����] word�� anagram�� ��� ����϶�.
		// �ܾ ������� ã�µ� �ʹ� ���� �ɸ���.
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

#pragma region ����
	// �ܾ���� �� �����ع����� ���� ���� ���� �� �ִ�.
	// dog -> dgo
	// god -> dgo

	ifstream in("�ܾ��.txt");
	if (!in)
	{
		cout << "������ �������� �ʽ��ϴ�." << endl;
	}

	// vecotr < pair<����string,����string> v;
	vector<PS> v;
	v.reserve(30'0000);
	string s;

	while (in >> s)
		v.emplace_back(s);

	cout << "���� �ܾ��� �� " << v.size() << endl;

	cout << "���� ��� - " << boolalpha << is_sorted(v.begin(), v.end()) << endl<<endl;

	//[����] v[i]�� first �������� ����
	sort(v.begin(), v.end(), [](const PS& a, const PS& b) {
		return a.first < b.first;
		});

	//[����] ã�� �ܾ��� anagram�� �ְ� ���� ã������!
	while (true) {
		string word;
		cout << "ã�� �ܾ�? ";
		cin >> word;

		auto [����, ����] = equal_range(v.begin(), v.end(),PS(word) ,
			[](const PS& a, const PS& b) {
				return a.first < b.first;
			});

		if (���� == ����) {
			cout << "���� �ܾ��Դϴ�." << endl;
			continue;
		}
		for (auto i = ����; i < ����; ++i) {
			cout << i->second << "   ";
		}
		cout << endl;
	}
	
#pragma endregion

		/*
		������ �Ǿ� �ֱ� ������ �� ������� ����Ž���� ��� �Ѵ�. 
		auto it =find(v.begin(), v.end(), word);
		
		if (it != v.end())
			cout << word << "�� �����մϴ�." << endl;
		else
			cout << word << "�������� �ʽ��ϴ�." << endl;
		*/
	
}