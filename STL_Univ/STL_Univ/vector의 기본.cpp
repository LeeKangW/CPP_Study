#include"default.h"
#include<vector>

int main() {

	vector<int> v{ 1,2,3,4,5 };

	cout << "���� ��ü�� ũ�� - " << sizeof(v) << endl;
	cout << "������ ���� �� -" << v.size() << endl;
	cout << "���� ���Ͱ� ���� �� �ִ� ������ ���� -" << v.capacity() << endl;
	cout << "�� �ý��ۿ��� vector<int>�� ���� �� �ִ� �ִ� ���� �� -" << v.max_size() << endl;

	cout << endl;

	cout << "���Ϳ� ����ִ� ���ҵ�" << endl;
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	v.push_back(6); // ���� 1�� �߰�

	cout << endl;

	cout << "���� ��ü�� ũ�� - " << sizeof(v) << endl;
	cout << "������ ���� �� -" << v.size() << endl;
	cout << "���� ���Ͱ� ���� �� �ִ� ������ ���� -" << v.capacity() << endl;
	cout << "�� �ý��ۿ��� vector<int>�� ���� �� �ִ� �ִ� ���� �� -" << v.max_size() << endl;

	cout << endl;

	cout << "���Ϳ� ����ִ� ���ҵ�" << endl;
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}