#include"default.h"
#include<set>
#include<iterator>

int main() {
	cout << "������ �Է��ϼ���. �������� Ctrl+z�� ��������" << endl << endl;

	multiset<string> ms{ istream_iterator<string>(cin),{} };

	cout << endl << "�������� ������ ����Դϴ�." << endl << endl;
	for (const string& s : ms)
		cout << s << endl;
}