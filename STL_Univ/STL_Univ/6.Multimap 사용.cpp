#include"default.h"
#include"String.h"
#include<map>
using namespace std;

int main() {

	try{
		unique_ptr<int[]> k{ new int[3] };
		k[0] = 1;
		k[1] = 2;
	cout << k.get();
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	/*
	multimap<String, String> movies;

	movies.insert(make_pair("�͹̳�����2", "���ӽ� ī�޷�"));
	movies.insert(movies.begin(), pair<String, String>("�μ���", "ũ�������� ���"));
	
	movies.emplace("�����", "����ȣ");

	movies.emplace("�������:�������", "�ȼҴ� ���, �� ���");
	movies.emplace("ũ���������� �Ǹ�", "�� ��ư");
	movies.emplace("�λ��� �Ƹ��ٿ�", "�κ����� ���ϴ�");
	movies.emplace("���ũ Ż��", "����ũ �ٶ�Ʈ");
	for (auto [����, ����] : movies)
		cout << ���� << " - " << ���� << endl;
		*/
}