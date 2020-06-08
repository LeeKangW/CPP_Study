#include"default.h"
#include<random>
#include<algorithm>

uniform_int_distribution<> uidAge(10, 50);
uniform_int_distribution<> uidName;
mt19937 dre;

class Player {
	int age;
	string name;

public:
	Player() {
		age = uidAge(dre);
		name += uidName(dre);
		name += uidName(dre);
	}
	void show() const {
		cout << age << " - " << name << endl;
	}
	int getAge() const {
		return age;
	}
	string getName()const {
		return name;
	}
};

int main() {

	Player players[1000];

	//[문제] 나이와 이름이 다 같이 오름차순이 되도록 하라.

	// 나이 오름차순으로 정렬하라.
	sort(begin(players), end(players), [](const Player& a, const Player& b) {
		return a.getAge() < b.getAge();
		});

	// 이름 오름차순으로 stable_sort하면 되지 않을까?
	stable_sort(begin(players), end(players), [](const Player& a, const Player& b) {
		return a.getName() < b.getName();
		});

	for (const Player& p : players)
		p.show();
}