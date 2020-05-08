// �ڵ� 8-6: �ζ� ��ȣ ������

#include"default.h"
#include<set>
#include<random>
using namespace std;

int main() {
	random_device rd;
	default_random_engine dre{ rd() };
	uniform_int_distribution<> uid{ 1,45 };

	set<int> s;

	while (s.size() < 6)
		s.insert(uid(dre));

	cout << "�̹� �� ��÷��ȣ:";
	for (int n : s)
		cout << n << ' ';
	cout << endl;
}