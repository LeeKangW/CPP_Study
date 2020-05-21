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
	unsigned int breakout{}; // 떼탈출 점수
	unsigned int championsLeague{}; // 챔피언스리그 점수
	static unsigned int id_num;
	// 그 외 필요한 멤버는 마음대로 추가하자	

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

void save_file(vector<Player>&);
void make_score(vector<Player>& );
void insert_score(vector<Player>&, vector<int>&);

#pragma endregion

string file1{ "STL과제.txt" };

int main() {
	vector<Player> players;
	players.reserve(10'0000); // 10'0000 명의 플레이어 생성

	ifstream in(file1);
	
	if (!in) {
		cout << "파일 존재 하지 않음... 데이터 새로 생성" << endl;
		default_random_engine dre;
		normal_distribution<> nd{ 0, 1.0 };
		for (int i = 0; i < players.capacity(); ++i) {
			double val = nd(dre);
			val += 5.0;
			if (val < 0)
				val = 0.0;
			if (10.0 < val)
				val = 10;
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
		cout << "5. 파일 확인" << endl;
		cout << "숫자 입력 -";
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
			make_score(players);
			break;
		case 4:
			cout << "파일을 저장합니다..." << endl;
			save_file(players);
			cout << "파일 저장 완료 !" << endl;
			break;
		case 5:
			for (const Player& p : players)
				p.show_score();
			break;
		default:
			cout << " 없는 메뉴입니다.." << endl;
			break;
		}

		if (input == 4)
			break;

		this_thread::sleep_for(chrono::milliseconds(500)); // 시간 지연

		system("cls"); // 화면 정리
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