#include"default.h"
#include<vector>
#include"String.h"


int main() {

	vector<String> v;
	v.reserve(2);
	//v.push_back(String("�ڷγ�"));
	v.emplace_back("�ڷγ�");

	cout << "------- ���� �߰� -------" << endl;
	//v.push_back(String("���̷���"));
	v.emplace_back("���̷���");
	//���Ҹ� �����ϴ� �����̳ʴ� ������� for�� �������.
	for (String& s : v)
		cout << s << endl;

}