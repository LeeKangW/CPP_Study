#include"default.h"
#include<vector>
#include"String.h"

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
	
	cout << "-----------" << endl;
	cout << "���Ҹ� �߰��ϱ� ��" << endl;
	// v�� ����Ͽ� ���ϴ� ���� �� ��ŭ �ߴ�. �׷��� ���Ұ� �� �� �� �ʿ��ϴ�.
	// �Ʒ��� ���� ���Ҹ� �߰��ϸ� � ���� �Ͼ��?

	v.emplace_back("PANDEMIC");

	cout << "���Ҹ� �߰��� ��" << endl;
	cout << "-----------" << endl;

	cout << "vector v�� �ּ�: " << &v << endl;

	cout << "������ ����: " << v.size() << endl;
	cout << "���Ұ� ����� �޸�: " << v.data() << endl;
	cout << "���Ҵ����� �ʰ� ���� �� �ִ� ����: " << v.capacity()<<endl;

}