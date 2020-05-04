#include"default.h"
#include<map>
#include <iomanip>
#include<vector>
#include<algorithm>

enum class Gender { Boy, Girl, Hybrid };
string Genders[]{ "���̱׷�","�ɱ׷�","ȥ���׷�" };

class IdolGroup {
	string groupName;	//�׷� �̸�
	Gender gender;		// ����
	int year;			// ����
	int num;			//�ο� ��
	string member;		//�����

public:
	explicit IdolGroup(string gn, Gender g, int y, int n, string m)
		:groupName{ gn }, gender{ g }, year{ y }, num{ n }, member{ m }{}

	void show() const {
		cout << "�̸�:" << left << setw(14) << groupName << setw(8)
			<< Genders[static_cast<int>(gender)] << "," << year << "��,"
			<< num << "��, ��� - " << member << endl;
	}
	
	int Get_year() const {
		return year;
	}
};

int main() {
	map<string, IdolGroup> idolGroups;

	idolGroups.insert(pair<string, IdolGroup>("�� �ý�����", IdolGroup("�� �ý�����", Gender::Girl, 1968, 2, "���μ�")));
	idolGroups.insert(make_pair("�۰��",
		IdolGroup("�۰��", Gender::Boy, 1979, 6, "��ö��")));

	auto koyote = make_pair("�ڿ���",
		IdolGroup("�ڿ���", Gender::Hybrid, 1998, 3, "������ ���� ����"));

	idolGroups.insert(koyote);

	idolGroups.emplace("������",
		IdolGroup("������", Gender::Girl, 2014, 4, "�ֶ� ���� ���� ȭ��"));

	// insert_or_assign -> �����͸� �ִµ�, Key ���� �ִٸ�, �������ش�.

	idolGroups.insert_or_assign("����",
		IdolGroup("����", Gender::Girl, 2019, 5, "���� ���� ���� ä�� ����"));

	vector<IdolGroup> v;
	v.reserve(idolGroups.size());

	
	for (const auto& ig : idolGroups)
		v.push_back(ig.second);

	sort(v.begin(), v.end(), [](IdolGroup a,IdolGroup b) {
		return a.Get_year() < b.Get_year();
		});

	for (const auto& sort_ig : v)
		sort_ig.show();
	
	
}