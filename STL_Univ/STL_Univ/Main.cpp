#include<iostream>
#include<string>
#include<random>
#include<fstream>
using namespace std;

#pragma region class Player

class Player
{
private:
	std::string id;
	unsigned int breakout; // 떼탈출 점수
	unsigned int championsLeague; // 챔피언스리그 점수
	// 그 외 필요한 멤버는 마음대로 추가하자	

public:
	Player() = default;
	
	void setScore(const int&,const int&);

	unsigned int get_Breakout() { return breakout; }
	unsigned int get_ChampionsLeague() { return championsLeague; }
	void show_score();
};
void Player::setScore(const int& b_score, const int& c_score){
	breakout = b_score;
	championsLeague = c_score;
}
void Player::show_score() {
	cout << breakout << "-" << championsLeague << endl;
}

#pragma endregion

void makeScore();

string file1{ "STL과제.txt" };
int main() {
	makeScore();

	

}

void makeScore() {

	random_device rd{};
	mt19937 gen{ rd() };
	normal_distribution<> uidBreakOut{ 1452943513,2 };

	ofstream out("STL과제.txt");
	for(int i=0;i<1000;++i)
	  cout << round(uidBreakOut(gen)) << endl;

	/*for (int i = 0; i < 10'0000; ++i) {
		Player player;
		player.setScore(uidBreakOut(dre), uidChampion(dre));
		out << player.get_Breakout() << "\t" << player.get_ChampionsLeague() << endl;
	}*/
	
}