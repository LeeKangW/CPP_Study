#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	ifstream in("�̻��ѳ����Ǿٸ���.txt",ios::app);
	ofstream out("�׽�Ʈ.txt");

	if (!in)
	{
		cout << "������ �������� �ʽ��ϴ�." << endl;
		return 0;
	}
	int c;

	// ���� ���� ���ԵǾ� �ִ�.
	while ((c = in.get()) != EOF)
	{
		out << (char)c;
	}


	/*
	// ���Ⱑ ������ �Ǿ� �ִ�. ( ����������� �� ���ڿ���ŭ ��� �ҷ����� ���� )
	string str;
	while (in >> str)
	{
		cout << str << endl;
	}
	*/

	cout << "��� �����Ͽ����ϴ�." << endl;
}