#include<iostream>
#include<string>
#include<iomanip>
#include <map>
#include<vector>
#include<algorithm>

using namespace std;

enum class Gender { Boy, Girl, Hybrid };
string Genders[]{ "���̱׷�", "�ɱ׷�", "ȥ���׷�" };
class IdolGroup {
	string groupName; // �׷� �̸�
	Gender gender; // ����
	int year; // ����
	int num; // �ο� ��
	string member; // �����
public:
	explicit IdolGroup(string gn, Gender g, int y, int n, string m)
		: groupName{ gn }, gender{ g }, year{ y }, num{ n }, member{ m } { }
	void show() const {
		cout << "�̸�:" << left << setw(14) << groupName << setw(8)
			<< Genders[static_cast<int>(gender)] << ", " << year << "��, "
			<< num << "��, ��� - " << member << endl;
	}
};
int main()
{
	map<string, IdolGroup> idolGroups;
	// ���ѹα��� ���̵� �׷� ��� - ��Ű�������
	idolGroups.insert(pair<string, IdolGroup>("�� �ý�����",
		IdolGroup("�� �ý�����", Gender::Girl, 1968, 2, "���μ�")));
	idolGroups.insert(make_pair("�۰��",
		IdolGroup("�۰��", Gender::Boy, 1979, 6, "��ö��")));
	auto koyote = make_pair("�ڿ���",
		IdolGroup("�ڿ���", Gender::Hybrid, 1998, 3, "������ ���� ����"));
	idolGroups.insert(idolGroups.begin(), koyote);
	idolGroups.emplace("������",
		IdolGroup("������", Gender::Girl, 2014, 4, "�ֶ� ���� ���� ȭ��"));
	idolGroups.insert_or_assign("����",
		IdolGroup("����", Gender::Girl, 2019, 5, "���� ���� ���� ä�� ����"));
	// ��ȸ�ϸ� ���
	
	vector<pair<string, IdolGroup>> v;
	v.reserve(idolGroups.size());

	for (const auto& t : idolGroups)
		v.push_back(t);

	sort(v.begin(), v.end(), [](const pair<string, IdolGroup>& a, const pair<string, IdolGroup>& b) {
		return a.first.size() > b.first.size();
		});
	
	for (auto [f, s] : v)
		cout << f;
		
	
}