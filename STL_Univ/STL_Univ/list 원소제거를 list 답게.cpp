#include"default.h"
#include"String.h"
#include<list>
#include<random>
int main() {

	default_random_engine engine;
	uniform_int_distribution<> uid{ 0,10 };

	list<int> numbers;

	for (int i = 0; i < 100; ++i)
		numbers.emplace_back(uid(engine));

	for (auto i = numbers.cbegin(); i != numbers.cend(); ++i)
		cout << *i << ' ';
	cout << endl;

	//numbers���� 0�� �����϶�.
	numbers.remove(0);

	cout << endl;
	cout << "0�� ������ �� numbers�� ���� �� : " << numbers.size() << endl;
	for (auto i = numbers.cbegin(); i != numbers.cend(); ++i)
		cout << *i << ' ';
	cout << endl;

}