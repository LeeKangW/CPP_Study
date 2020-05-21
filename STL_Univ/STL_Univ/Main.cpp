#include<iostream>
#include<string>
#include<random>
#include<fstream>
#include<algorithm>
#include<iomanip>
#include<chrono>
#include<thread>

using namespace std;

#pragma region class Player

class Player
{
private:
	std::string id{};
	unsigned int breakout{}; // ��Ż�� ����
	unsigned int championsLeague{}; // è�Ǿ𽺸��� ����
	static unsigned int id_num;
	// �� �� �ʿ��� ����� ������� �߰�����	

public:
	Player() = default;
	Player(string name,unsigned int, unsigned int);
	unsigned int get_Breakout() const { return breakout; }
	unsigned int get_ChampionsLeague() const { return championsLeague; }
	void set_BreakOut(unsigned int); 
	void set_ChampionsLeague(unsigned int);
	void show_score() const;
	friend ifstream& operator>>(ifstream&, Player&);
	friend ofstream& operator<<(ofstream&, Player&);
};
unsigned int  Player::id_num{ 1 };

Player::Player(string name,unsigned int b_score, unsigned int c_score):breakout(b_score),championsLeague(c_score) {
	id = name + to_string(id_num);
	++id_num;
}
void Player::set_BreakOut(unsigned int num) {
	if (breakout < num)
		breakout = num;
}
void Player::set_ChampionsLeague(unsigned int num) {
	if (championsLeague < num)
		championsLeague = num;
}
void Player::show_score() const {
	cout << id << "�� ��Ż�� ���� - "<< right<<setw(10)<< breakout << ", " 
		<< "è�Ǿ� ���� ���� - "<< right<< setw(10)<<championsLeague << endl;
}
ifstream& operator>>(ifstream& in, Player& rhs) {
	in >> rhs.id;
	in >> rhs.breakout;
	in >> rhs.championsLeague;

	return in;
}
ofstream& operator<<(ofstream& out, Player& rhs) {
	out << rhs.id<<' ';
	out << rhs.breakout<<' ';
	out << rhs.championsLeague<<' ';

	return out;
}

#pragma endregion

#pragma region �Լ� ����

void save_file(vector<Player>&);
void make_score(vector<Player>& );
void insert_score(vector<Player>&, vector<int>&);

#pragma endregion

string file1{ "STL����.txt" };

int main() {
	vector<Player> players;
	players.reserve(10'0000); // 10'0000 ���� �÷��̾� ����

	ifstream in(file1);
	
	if (!in) {
		cout << "���� ���� ���� ����... ������ ���� ����" << endl;
		default_random_engine dre;
		normal_distribution<> nd{ 0, 1.0 };
		for (int i = 0; i < players.capacity(); ++i) {
			double val = nd(dre);
			val += 5.0;
			if (val < 0)
				val = 0.0;
			if (10.0 < val)
				val = 10;
			players.emplace_back("��Ű��", val * 290588702.6, val * 111267038.4);
		}
	}
	else {
		for (int i = 0; i < players.capacity(); ++i) {
			Player player;
			in >> player;
			players.push_back(player);
		}
	}
	
	while (true) {
		cout << "��Ű�� : ����극��ũ ��ŷ" << endl;
		cout << "1. ���� ����" << endl;
		cout << "2. ���� ��Ż�� ��ŷ" << endl;
		cout << "3. ���� è�Ǿ� ���� ��ŷ" << endl;
		cout << "4. ������" << endl;
		cout << "5. ���� Ȯ��" << endl;
		cout << "���� �Է� -";
		int input;
		cin >> input;

		if (cin.fail()) { // ���� �Է� ����.
			cout << "���� �޴��Դϴ�." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		switch (input)
		{
		case 1:
			make_score(players);
			break;
		case 4:
			cout << "������ �����մϴ�..." << endl;
			save_file(players);
			cout << "���� ���� �Ϸ� !" << endl;
			break;
		case 5:
			for (const Player& p : players)
				p.show_score();
			break;
		default:
			cout << " ���� �޴��Դϴ�.." << endl;
			break;
		}

		if (input == 4)
			break;

		this_thread::sleep_for(chrono::milliseconds(500)); // �ð� ����

		system("cls"); // ȭ�� ����
	}
}

void save_file(vector<Player>& players) {
	ofstream out(file1);
	for (int i = 0; i < players.size(); ++i) {
		out << players.at(i);
	}
}
void make_score(vector<Player>& players) {
	random_device rd;
	default_random_engine dre{ rd() };

	vector<int> v;

	v.reserve(10'0000);

	for (int i = 0; i < v.capacity(); ++i)
		v.emplace_back(i);

	shuffle(v.begin(), v.end(), dre);

	insert_score(players, v);
}
void insert_score(vector<Player>& players, vector<int>& v) {
	default_random_engine dre;
	normal_distribution<> nd{ 0, 1.0 };

	for (int i = 0; i < players.size(); ++i) {
		double val = nd(dre);
		val += 5.0;
		if (val < 0)
			val = 0.0;
		if (10.0 < val)
			val = 10;
		if (i < 5'0000) { // ��Ż�� ���� ����.
			val *= 290588702.6;

			players.at(v.at(i)).set_BreakOut((unsigned int)val);
		}
		else { // è�Ǿ� ���� ���� ����.
			val *= 111267038.4;
			players.at(v.at(i)).set_ChampionsLeague((unsigned int)val);
		}
	}
}