#include"default.h"
#include"String.h"
#include<map>
using namespace std;

int main() {

	try{
		unique_ptr<int[]> k{ new int[3] };
		k[0] = 1;
		k[1] = 2;
	cout << k.get();
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	/*
	multimap<String, String> movies;

	movies.insert(make_pair("터미네이터2", "제임스 카메론"));
	movies.insert(movies.begin(), pair<String, String>("인셉션", "크리스토퍼 놀란"));
	
	movies.emplace("기생충", "봉준호");

	movies.emplace("어밴져스:엔드게임", "안소니 루소, 조 루소");
	movies.emplace("크리스마스의 악몽", "팀 버튼");
	movies.emplace("인생은 아름다워", "로베르토 베니니");
	movies.emplace("쇼생크 탈출", "프랭크 다라본트");
	for (auto [제목, 감독] : movies)
		cout << 제목 << " - " << 감독 << endl;
		*/
}