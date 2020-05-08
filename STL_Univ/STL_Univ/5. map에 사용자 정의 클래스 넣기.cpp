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
	// less�� �̿��� ���
	// map<String, String,less<String>> movies;

	// ȣ�Ⱑ��Ÿ���� ���� �����ϴ� ���

	/*
	map<String, String, function<bool(const String&, const String&)>>
		movies(StringCmp);
	*/
	map<String, String> movies;

	movies.insert(make_pair("�͹̳�����2", "���ӽ� ī�޷�"));
	movies.insert(movies.begin(), pair<String, String>("�μ���", "ũ�������� ���"));

	movies.emplace("�����", "����ȣ");

	movies["�����:�������"] = "�ȼҴ� ���, �� ���";
	movies["ũ���������� �Ǹ�"] = "�� ��ư";

	movies.insert_or_assign("�λ��� �Ƹ��ٿ�", "�κ����� ���ϴ�");
	movies.try_emplace(movies.end(), "���ũ Ż��", "����ũ �ٶ�Ʈ");

	for (auto [����, ����] : movies)
		cout << ���� << " - " << ���� << endl;
}