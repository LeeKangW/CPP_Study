#include"default.h"
#include<deque>
#include<algorithm>
#include"String.h"


int main() {
	deque<String> news;
	news.push_back(String{ "日 경찰 술판으로 집단감염" });
	news.push_front(String{ "日 엉터리 검사에 병원내 감염 속출" });

	news.emplace_back("일본 전국적 감염 만연 단계");
	news.emplace_back("日유권자 긴급사태 너무 늦어..");

	cout << "관찰 메시지 off" << endl;
	cout << endl;

	cout << "deque에 저장된 모든 원소 출력" << endl;

	cout << endl;

	for (const String& news : news)
		cout << news << endl;

	cout << endl;

	// 글자 수 오름차순으로 정렬
	sort(news.begin(), news.end(), [](const String& a, const String& b) {
		return a.size() < b.size();
		});

	// 결과 출력
	cout << "글자 수 오름차순 정렬" << endl;
	cout << endl;
	for (int i = 0; i < news.size(); ++i)
		cout << news[i] << endl;
	cout << endl;

	//결과를 반대로 출력
	cout << "글자 수 내림차순 정렬" << endl;
	cout << endl;
	for (auto i = news.begin(); i < news.end(); ++i) {
		cout << *i << endl;
	}
	cout << endl;
}