#include"default.h"
#include<map>
#include<functional>
#include"String.h"
using namespace std;

bool StringCmp(const String& a, const String& b) {
	return a.getString()< b.getString();
}

template<>
struct less<String>
{
	bool operator()(const String& a, const String& b) const {
		return a.getString() < b.getString();
	}
};
int main() {
	// less를 이용한 방법
	// map<String, String,less<String>> movies;

	// 호출가능타입을 직접 정의하는 방법

	/*
	map<String, String, function<bool(const String&, const String&)>>
		movies(StringCmp);
	*/
	map<String, String> movies;

	movies.insert(make_pair("터미네이터2", "제임스 카메론"));
	movies.insert(movies.begin(), pair<String, String>("인셉션", "크리스토퍼 놀란"));

	movies.emplace("기생충", "봉준호");

	movies["어벤져스:엔드게임"] = "안소니 루소, 조 루소";
	movies["크리스마스의 악몽"] = "팀 버튼";

	movies.insert_or_assign("인생은 아름다워", "로베르토 베니니");
	movies.try_emplace(movies.end(), "쇼생크 탈출", "프랭크 다라본트");

	for (auto [제목, 감독] : movies)
		cout << 제목 << " - " << 감독 << endl;
}