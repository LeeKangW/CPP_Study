#include"default.h"
#include<map>
#include <iomanip>

enum class Gender { Boy, Girl, Hybrid };
string Genders[]{ "보이그룹","걸그룹","혼성그룹" };

class IdolGroup {
	string groupName;	//그룹 이름
	Gender gender;		// 성별
	int year;			// 데뷔
	int num;			//인원 수
	string member;		//멤버들

public:
	explicit IdolGroup(string gn, Gender g, int y, int n, string m)
		:groupName{ gn }, gender{ g }, year{ y }, num{ n }, member{ m }{}

	void show() const {
		cout << "이름:" << left << setw(14) << groupName << setw(8)
			<< Genders[static_cast<int>(gender)] << "," << year << "년,"
			<< num << "명, 멤버 - " << member << endl;
	}
};

int main() {
	map<string, IdolGroup> idolGroups;

	idolGroups.insert(pair<string, IdolGroup>("펄 시스터즈", IdolGroup("펄 시스터즈", Gender::Girl, 1968, 2, "배인순")));
	idolGroups.insert(make_pair("송골매",
		IdolGroup("송골매", Gender::Boy, 1979, 6, "배철수")));

	auto koyote = make_pair("코요태",
		IdolGroup("코요태", Gender::Hybrid, 1998, 3, "김종민 신지 빽가"));

	idolGroups.insert(koyote);

	idolGroups.emplace("마마무",
		IdolGroup("마마무", Gender::Girl, 2014, 4, "솔라 문별 휘인 화사"));

	// insert_or_assign -> 데이터를 넣는데, Key 값이 있다면, 수정해준다.

	idolGroups.insert_or_assign("있지",
		IdolGroup("있지", Gender::Girl, 2019, 5, "예지 리아 류진 채령 유리"));


	cout << "*** 아이돌 척척박사 ***" << endl;
	while (true) {
		cout << "궁금하신 그룹의 이름을 입력해 주세요:";
		string name;
		cin >> name;

		auto p = idolGroups.find(name);
		if (p != idolGroups.end())
			p->second.show();
		else
			cout << name << "- 없는 그룹입니다." << endl;

		cout << endl;
	}


}