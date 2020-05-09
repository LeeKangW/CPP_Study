#include<iostream>
#include<list>
#include<random>

using namespace std;

int main() {
	default_random_engine dre;
	uniform_int_distribution<> uid{ 0,10 };

	list<int> numbers;

	for (int i = 0; i < 100; ++i)
		numbers.emplace_back(uid(dre));

	cout << "0�� ���� �� numbers�� ���� ��: " << numbers.size() << endl;
	for (auto i = numbers.cbegin(); i != numbers.cend(); ++i)
		cout << *i << ' ';
	cout << endl;

	// number���� 0 ����
	numbers.remove(0);
	cout << endl;
	cout << "0�� ������ �� numbers�� ���� ��: " << numbers.size() << endl;
	for (auto i = numbers.cbegin(); i != numbers.cend(); ++i)
		cout << *i << ' ';
	cout << endl;


}