#include"default.h"
#include<vector>
#include"String.h"

int main() {

	vector<String> v{ "�Ϻ�","�ڷγ�","�ű�Ȯ��","700��" };

	cout << "vector v�� �ּ� : " << &v << endl;

	cout << "������ ����: " << v.size() << endl;
	cout << "���Ұ� ����� �޸�: " << v.data() << endl;
	cout << "���Ҵ����� �ʰ� ���� �� �ִ� ����: " << v.capacity() << endl;

	//�����̳��� ��� ���Ҹ� ��ȸ�Ϸ��� range-based for�� �������
	for (const String& str : v)
		cout << str << endl;
}