#include"default.h"
#include<string>
#include<vector>
#include<fstream>
#include<iterator>
#include<algorithm>

// ���� Ž�� - ���ĵ� �����Ͱ� �ִٸ� �̷��� ã�ƾ� �ڴ�.

// "�̻��ѳ����Ǿٸ���.txt"�� �о ����

int main() {
	
	ifstream in("�̻��ѳ����Ǿٸ���.txt");
	
	vector<string> v{ istream_iterator<string>{in},{} };		// {} -> EOF �� �� ��.

	cout << v.size() <<"�ܾ �о���."<< endl;

	sort(v.begin(), v.end());

	// [����] ã�� �ܾ �ִٸ� ��� �ִ��� ��� �ִ��� 
	// �˷��ִ� ���α׷��� ������.
	// [���� ����] ���ĵ� ���¸� ���߸��� �ʰ�, word�� ������� �� �ִ�
	// ��ġ�� ã�ƶ�. -> equal_range �Լ�

	while (true) {
		cout << endl << " �ܾ �Է��ϼ��� : ";
		string word;
		cin >> word;

		auto [�ο�,����] = equal_range(v.begin(), v.end(), word);

		if (�ο� == ����)
			cout << word << "�� ������ ���� �ܾ��Դϴ�." << endl;
		else
			cout << ���� - �ο� << "���� " << word << "�� �ֽ��ϴ�." << endl;

		copy(�ο� - 1, ���� + 1, ostream_iterator<string>(cout, " "));
		/*
		// auto p  = find(v.begin(), v.end(), word);
		auto p = binary_search(v.begin(), v.end(), word); // ���ĵ� ���¿����� ���� Ž������ ã�ƾ� �Ѵ�.
		if (p)
			cout << word << "�� ã�ҽ��ϴ�." << endl;
		else
			cout << "���� �ܾ��Դϴ�." << endl;
		*/
	}
}