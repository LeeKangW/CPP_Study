#include"default.h"
#include<fstream>

void save(string str) { // save ����

	// ������ ���� ������ ���� -> "���������.cpp"
	ifstream in(str);
	//���� ������ ������ ������ ���� -> ������ �����̸��� "��������.txt" ��� ����
	ofstream out("���� ����.txt", ios::app); // ios::app ���ٿ����� 
	//���������.cpp�� ��� ������ �о� ��������.txt ���Ͽ� ����Ѵ�.
	int c;
	out << endl;
	while ((c = in.get()) != EOF)
		out << (char)c;

	cout << str << "�� ��������.txt�� �����Ͽ����ϴ�." << endl;

}