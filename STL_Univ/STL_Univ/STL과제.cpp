#include<iostream>
#include<string>
#include<random>
#include<fstream>
#include<algorithm>
#include<iomanip>
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
	string_view get_Id()const { return id; }
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

void search_id(vector<Player>&, int&);
void search_breakout_percent(vector<Player>&, string&);
void serach_champion_percent(vector<Player>&, string&);
void save_file(vector<Player>&);
void make_score(vector<Player>& );
void insert_score(vector<Player>&, vector<int>&);

#pragma endregion

string file1{ "STL����.txt" };
const double aver{ 0.0 };
const double standard_deviation{ 3.0 };
int main() {
	vector<Player> players;
	players.reserve(10'0000); // 10'0000 ���� �÷��̾� ����

	ifstream in(file1);
	
		if (!in) {
			cout << "���� ���� ���� ����... ������ ���� ����" << endl;
			default_random_engine dre;
			normal_distribution<> nd{ aver, standard_deviation };
				for (int i = 0; i < players.capacity(); ++i) {
					double val = nd(dre);
					val = clamp(val, -5.0, 5.0);
					val += 5.0;

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
			//cout << "5. ���� Ȯ��" << endl;
			cout << "���� �Է� - ";
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
					cout << "���� ����!" << endl;
					make_score(players);
					cout << "���� ����!" << endl;
					break;
				case 2:
				case 3:
					search_id(players, input);
					break;
				case 4:
					cout << "������ �����մϴ�..." << endl;
					save_file(players);
					cout << "���� ���� �Ϸ� !" << endl;
					break;
					/*
				case 5:
					for (const Player& p : players)
						p.show_score();
					break;
					*/
				default:
					cout << " ���� �޴��Դϴ�.." << endl;
					break;
				}

				if (input == 4)
					break;

			this_thread::sleep_for(1500ms); // �ð� ����

			system("cls"); // ȭ�� ����
		}
}
#pragma region 2��, 3�� ���̵� ã��.
void search_id(vector<Player>& players, int& menu_num) {
	cout << "Id �Է� : ";
	string name{};
	cin >> name;
	auto it = find_if(players.begin(), players.end(), [&](const Player& a) {
			return a.get_Id() == name;
			});
	if (it!=players.end()) {

		cout << name << " �÷��̾ ã�ҽ��ϴ�." << endl;
		cout << "�����͸� �ҷ����� ��..." << endl;

			if (menu_num == 2) { // ��Ż�� 
				sort(players.begin(), players.end(), [](const Player& a, const Player& b) {
					return a.get_Breakout() > b.get_Breakout();
					});

				cout << "������ �ٿ�ε� �Ϸ�..." << endl;
				search_breakout_percent(players, name);
			}
			else { // è�Ǿ� ����
				sort(players.begin(), players.end(), [](const Player& a, const Player& b) {
					return a.get_ChampionsLeague() > b.get_ChampionsLeague();
					});

				cout << "������ �ٿ�ε� �Ϸ�..." << endl;
				serach_champion_percent(players, name);
			}
	}
	else {
		cout << name << " �÷��̾ �������� �ʽ��ϴ�." << endl;
	}
}
#pragma endregion

#pragma region ��Ż�� ���� % ã��.
void search_breakout_percent(vector<Player>& players,string& name) {
	auto it = find_if(players.begin(), players.end(), [&](const Player& a) {
		return a.get_Id() == name;
		});

	auto index = distance(players.begin(), it);
	double percent = ((double)index / players.size()) * 100;

	cout << endl << "======= ��Ż�� =======" << endl;

	cout << fixed;		// �Ҽ��� ���� 
	cout.precision(1);  // 2�ڸ� ���� ���

	cout << right << setw(10) << players.at(index - 1).get_Id() << right << setw(7) << index - 1 << "�� ���� "<< percent << "% ����" << right << setw(11) << players.at(index - 1).get_Breakout() << endl;
	cout << right << setw(10) << players.at(index).get_Id() << right << setw(7) << index << "�� ���� "  << percent << "% ����" << right << setw(11) << players.at(index).get_Breakout() << endl;
	cout << right << setw(10) << players.at(index+1).get_Id() << right << setw(7) << index+1 << "�� ���� "<< percent << "% ����" << right << setw(11) << players.at(index+1).get_Breakout() << endl;
}
#pragma endregion

#pragma region è�Ǿ� ���� ���� % ã��.
void serach_champion_percent(vector<Player>& players, string& name) {
	auto it = find_if(players.begin(), players.end(), [&](const Player& a) {
		return a.get_Id() == name;
		});
	auto index = distance(players.begin(), it);

	double percent = ((double)index / players.size()) * 100;

	cout << endl << "======= è�Ǿ� ���� =======" << endl;

	cout << fixed;		// �Ҽ��� ���� 
	cout.precision(1);  // 2�ڸ� ���� ���

	cout << right<< setw(10) << players.at(index-1).get_Id() << right << setw(7) << index - 1 << "�� ���� "<< percent <<"% ����" << right << setw(11) << players.at(index - 1).get_Breakout() << endl;
	cout << right << setw(10) << players.at(index).get_Id() << right << setw(7) << index << "�� ���� "  << percent << "% ����" << right << setw(11) << players.at(index).get_Breakout() << endl;
	cout << right << setw(10) << players.at(index+1).get_Id() << right << setw(7) << index + 1 << "�� ���� "<< percent << "% ����" << right << setw(11) << players.at(index + 1).get_Breakout() << endl;
}
#pragma endregion

#pragma region ���� ����.
void save_file(vector<Player>& players) {
	ofstream out(file1);
	for (int i = 0; i < players.size(); ++i) {
		out << players.at(i);
	}
}
#pragma endregion

#pragma region ���ھ� �����.

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
	normal_distribution<> nd{ aver, standard_deviation };

		for (int i = 0; i < players.size(); ++i) {
			double val = nd(dre);
			val = clamp(val, -5.0, 5.0);
			val += 5.0;

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
#pragma endregion