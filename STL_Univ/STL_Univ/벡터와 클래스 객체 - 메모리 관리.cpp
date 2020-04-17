#include"default.h"
#include<vector>
#include"String.h"
#include <algorithm>

int main() {
	vector<String> v;

	v.reserve(4);

	v.emplace_back("�Ϻ�");
	v.emplace_back("�ڷγ�");
	v.emplace_back("�ű�Ȯ��");
	v.emplace_back("700��");

	cout << "vector v�� �ּ�: " << &v << endl;

	cout << "������ ����: " << v.size() << endl;
	cout << "���Ұ� ����� �޸�: " << v.data() << endl;
	cout << "���Ҵ����� �ʰ� ���� �� �ִ� ����: " << v.capacity() << endl;

	/*
	cout << "������������ �����մϴ�." << endl;

	sort(v.begin(), v.end(), [](String a, String b) {
		return a.getString() < b.getString();
		});
	cout << "������������ ������ ����Դϴ�" << endl;
	*/

	//�����̳��� ��� ���Ҹ� ��ȸ�Ϸ��� range-based for�� �������
	for (const String& str : v)
		cout << str << endl;
}