#include<iostream>
#include<random>
#include<fstream>
#include<string>
#include<iomanip>
#include<vector>
using namespace std;

void makeData();

class Player {
	int year;
	int month;
	string name;

public:
	Player() = default;
	Player(int y, int m, string n) :year{ y }, month{ m }, name{ n }{}
	int getYear()const { return year; }
	int getMonth()const { return month; }
	string getName() const { return name; }
	
	void show() const {
		cout << year << ", " << setw(2) << month << ", " << name << endl;
	}
};

int main() {
	// makeData();
	ifstream in("�⸻.dat", ios::binary);

	if (!in)
	{
		cout << "������ �������� �ʽ��ϴ�." << endl;
		return 0;
	}
	vector<Player> v;
	v.reserve(10'0000);
#pragma region Q1
	for (int i = 0; i < 10'0000; ++i)
	{
		Player p;
		in.read((char*)&p, sizeof(Player));
		v.push_back(p);
	}
	cout << "���� 1�� - ";
	(--v.end())->show();
#pragma endregion
#pragma region Q2
	sort(v.begin(), v.end(), [](const Player& a, const Player& b) {
		if (a.getYear() == b.getYear()) {
			return a.getName() < b.getName();
		}
		else {
			return a.getYear() < b.getYear();
		}
		});
	cout << "���� 2�� - ";
	(--v.end())->show();
#pragma endregion
#pragma region Q3
	Player p{ 1999,1,"test" };

	auto [��������, ��������] = equal_range(v.begin(), v.end(), p , [](const Player& a, const Player& b) {
		return a.getYear() < b.getYear();
		});

	auto [����,����] = equal_range(��������, ��������, p, [](const Player& a, const Player& b) {
		return a.getName() < b.getName();
		});
	
	v.insert(����, p);

#pragma endregion

#pragma region Q4
	cout << "Q4 ����" << endl;
	int year{ 1950 };
	int cnt{};
	for (; year < 2010 + 1; ++year)
	{
		auto [b, e] = equal_range(v.begin(), v.end(), Player(year,1,""), [](const Player& a, const Player& b) {
			return a.getYear() < b.getYear();
			});
		cout << year << "�⵵ ������ ���� - " << e - b << endl;
		cnt+=(e - b);
	}
	/*for (; year < 2010 + 1; ++year) {
		cout << year << "�⵵ ���� : " << count_if(v.begin(), v.end(), [&](const Player& a) {return a.getYear() == year; }) << endl;
	}*/
	cout << "�� ���� -" << cnt << endl;
#pragma endregion
	

}

void makeData() {
	ofstream out("�⸻.dat", ios::binary);

	default_random_engine dre;
	uniform_int_distribution<int> year{ 1950,2010 };
	uniform_int_distribution<int> month{ 1,12 };
	uniform_int_distribution<int> name { 'a','z' };
	uniform_int_distribution<int> len{ 3,15 };

	for (int i = 0; i < 10'0000; ++i) {
		string s{};

		for (int j = 0;j < len(dre); ++j)
			s += name(dre);
		*s.begin() = toupper(*s.begin());

		Player p{ year(dre),month(dre),s };
		
		out.write((const char*)&p, sizeof(Player));
	}
	cout << "10������ ���� ������ ���Ͽ� ����Ͽ���" << endl;
}