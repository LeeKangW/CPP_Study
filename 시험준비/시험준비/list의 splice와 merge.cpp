#include<iostream>
#include<list>
#include<algorithm>
#include<string>
using namespace std;

void print(string, list<int>&);

int main() {
	list<int> odd{ 5, 1, 3, 9, 7 };
	list<int> even{ 2, 6, 10, 4, 8 };
	list<int> num;
	cout << "--- �����̳��� ���� ��� ---" << endl;
	print("odd: ", odd);
	print("even: ", even);
	print("num: ", num);

	num.merge(odd);
	num.merge(even);
	cout << endl << "--- merge ��� ---" << endl;
	print("odd: ", odd);
	print("even: ", even);
	print("num: ", num);

	list<int> part;
	part.splice(part.begin(), num, ++++num.begin(), ------num.end());

	cout << endl << "--- splice ��� ---" << endl;
	print("num: ", num);
	print("part: ", part);
}
void print(string name, list<int>& cont)
{
	cout << name;
	for (int n : cont)
		cout << n << ' ';
	cout << endl;
}