#include <iostream>
#include <fstream>
#include <random>
using namespace std;
int main()
{
	/*
	ofstream out("���� ����");
	default_random_engine dre;
	uniform_int_distribution<> uid(0, 10'0000);
	for (int i = 0; i < 1'0000; ++i) {
		out << uid(dre) << " ";
		if (i % 10 == 9)
			out << endl;
	}
	*/
	ifstream in("���� ����");

	vector<int> v;
	v.reserve(1'0000);
	int c = 0;

	while (in >> c) {
		v.emplace_back(c);
	}
	
	auto a = count_if(v.begin(), v.end(), [](int a) {
					if (0 <= a && a < 1'0000)
						return true;
					return false;
					});
	
	cout << "���� ���� : " << a<<endl;
	cout << "a�� Ÿ��" << typeid(a).name() << endl;
}