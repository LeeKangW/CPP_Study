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
	unsigned int breakout{}; // 떼탈출 점수
	unsigned int championsLeague{}; // 챔피언스리그 점수
	static unsigned int id_num;
	// 그 외 필요한 멤버는 마음대로 추가하자	

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
	cout << id << "의 떼탈출 점수 - "<< right<<setw(10)<< breakout << ", " 
		<< "챔피언스 리그 점수 - "<< right<< setw(10)<<championsLeague << endl;
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

#pragma region 함수 선언

void search_id(vector<Player>&, int&);
void search_breakout_percent(vector<Player>&, string&);
void serach_champion_percent(vector<Player>&, string&);
void save_file(vector<Player>&);
void make_score(vector<Player>& );
void insert_score(vector<Player>&, vector<int>&);

#pragma endregion

string file1{ "STL과제.txt" };
const double aver{ 0.0 };
const double standard_deviation{ 3.0 };
int main() {
	vector<Player> players;
	players.reserve(10'0000); // 10'0000 명의 플레이어 생성

	ifstream in(file1);
	
		if (!in) {
			cout << "파일 존재 하지 않음... 데이터 새로 생성" << endl;
			default_random_engine dre;
			normal_distribution<> nd{ aver, standard_deviation };
				for (int i = 0; i < players.capacity(); ++i) {
					double val = nd(dre);
					val = clamp(val, -5.0, 5.0);
					val += 5.0;

					players.emplace_back("쿠키런", val * 290588702.6, val * 111267038.4);
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
			cout << "쿠키런 : 오븐브레이크 랭킹" << endl;
			cout << "1. 게임 진행" << endl;
			cout << "2. 나의 떼탈출 랭킹" << endl;
			cout << "3. 나의 챔피언스 리그 랭킹" << endl;
			cout << "4. 나가기" << endl;
			//cout << "5. 파일 확인" << endl;
			cout << "숫자 입력 - ";
			int input;
			cin >> input;

				if (cin.fail()) { // 문자 입력 방지.
					cout << "없는 메뉴입니다." << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					continue;
				}
				switch (input)
				{
				case 1:
					cout << "시즌 시작!" << endl;
					make_score(players);
					cout << "시즌 종료!" << endl;
					break;
				case 2:
				case 3:
					search_id(players, input);
					break;
				case 4:
					cout << "파일을 저장합니다..." << endl;
					save_file(players);
					cout << "파일 저장 완료 !" << endl;
					break;
					/*
				case 5:
					for (const Player& p : players)
						p.show_score();
					break;
					*/
				default:
					cout << " 없는 메뉴입니다.." << endl;
					break;
				}

				if (input == 4)
					break;

			this_thread::sleep_for(1500ms); // 시간 지연

			system("cls"); // 화면 정리
		}
}
#pragma region 2번, 3번 아이디 찾기.
void search_id(vector<Player>& players, int& menu_num) {
	cout << "Id 입력 : ";
	string name{};
	cin >> name;
	auto it = find_if(players.begin(), players.end(), [&](const Player& a) {
			return a.get_Id() == name;
			});
	if (it!=players.end()) {

		cout << name << " 플레이어를 찾았습니다." << endl;
		cout << "데이터를 불러오는 중..." << endl;

			if (menu_num == 2) { // 떼탈출 
				sort(players.begin(), players.end(), [](const Player& a, const Player& b) {
					return a.get_Breakout() > b.get_Breakout();
					});

				cout << "데이터 다운로드 완료..." << endl;
				search_breakout_percent(players, name);
			}
			else { // 챔피언스 리그
				sort(players.begin(), players.end(), [](const Player& a, const Player& b) {
					return a.get_ChampionsLeague() > b.get_ChampionsLeague();
					});

				cout << "데이터 다운로드 완료..." << endl;
				serach_champion_percent(players, name);
			}
	}
	else {
		cout << name << " 플레이어가 존재하지 않습니다." << endl;
	}
}
#pragma endregion

#pragma region 떼탈출 상위 % 찾기.
void search_breakout_percent(vector<Player>& players,string& name) {
	auto it = find_if(players.begin(), players.end(), [&](const Player& a) {
		return a.get_Id() == name;
		});

	auto index = distance(players.begin(), it);
	double percent = ((double)index / players.size()) * 100;

	cout << endl << "======= 떼탈출 =======" << endl;

	cout << fixed;		// 소수점 부터 
	cout.precision(1);  // 2자리 까지 출력

	cout << right << setw(10) << players.at(index - 1).get_Id() << right << setw(7) << index - 1 << "등 상위 "<< percent << "% 점수" << right << setw(11) << players.at(index - 1).get_Breakout() << endl;
	cout << right << setw(10) << players.at(index).get_Id() << right << setw(7) << index << "등 상위 "  << percent << "% 점수" << right << setw(11) << players.at(index).get_Breakout() << endl;
	cout << right << setw(10) << players.at(index+1).get_Id() << right << setw(7) << index+1 << "등 상위 "<< percent << "% 점수" << right << setw(11) << players.at(index+1).get_Breakout() << endl;
}
#pragma endregion

#pragma region 챔피언스 리그 상위 % 찾기.
void serach_champion_percent(vector<Player>& players, string& name) {
	auto it = find_if(players.begin(), players.end(), [&](const Player& a) {
		return a.get_Id() == name;
		});
	auto index = distance(players.begin(), it);

	double percent = ((double)index / players.size()) * 100;

	cout << endl << "======= 챔피언스 리그 =======" << endl;

	cout << fixed;		// 소수점 부터 
	cout.precision(1);  // 2자리 까지 출력

	cout << right<< setw(10) << players.at(index-1).get_Id() << right << setw(7) << index - 1 << "등 상위 "<< percent <<"% 점수" << right << setw(11) << players.at(index - 1).get_Breakout() << endl;
	cout << right << setw(10) << players.at(index).get_Id() << right << setw(7) << index << "등 상위 "  << percent << "% 점수" << right << setw(11) << players.at(index).get_Breakout() << endl;
	cout << right << setw(10) << players.at(index+1).get_Id() << right << setw(7) << index + 1 << "등 상위 "<< percent << "% 점수" << right << setw(11) << players.at(index + 1).get_Breakout() << endl;
}
#pragma endregion

#pragma region 파일 저장.
void save_file(vector<Player>& players) {
	ofstream out(file1);
	for (int i = 0; i < players.size(); ++i) {
		out << players.at(i);
	}
}
#pragma endregion

#pragma region 스코어 만들기.

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

				if (i < 5'0000) { // 떼탈출 정보 저장.
					val *= 290588702.6;

					players.at(v.at(i)).set_BreakOut((unsigned int)val);
				}
				else { // 챔피언스 리그 정보 저장.
					val *= 111267038.4;
					players.at(v.at(i)).set_ChampionsLeague((unsigned int)val);
				}
		}
}
#pragma endregion