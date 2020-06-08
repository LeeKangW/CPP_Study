#include<iostream>
#include<numeric>
#include<algorithm>
#include<iterator>
#include<random>

using namespace std;

// ���� ���� �˰��� ���⵵ ���� �� --> ���⵵�� ���� ��
// partition -> nth_element -> partial_sort -> sort -> stable_sort

int main() {

	int a[100];										// ���� 100�� �غ�
	iota(begin(a), end(a), 1);						// [1,100] ä���.

	copy(begin(a), end(a), ostream_iterator<int>(cout, "\t"));

	mt19937 dre;
	shuffle(begin(a), end(a), dre);

	cout << endl << "�����͸� ����" << endl;
	copy(begin(a), end(a), ostream_iterator<int>(cout, "\t"));

// Q1. Ȧ���� ¦���� �и��Ͽ� ���� ����϶�. - partition
	auto it = partition(begin(a), end(a), [](const int a) {
			return a & 1;
			});
	cout << endl << "Ȧ��" << endl;
	copy(begin(a), it, ostream_iterator<int>(cout, "\t"));
	cout << endl << "¦��" << endl;
	copy(it, end(a), ostream_iterator<int>(cout, "\t"));

// [����] 1����� 30����� ������� �̾��� - partial_sort

	partial_sort(begin(a), begin(a) + 30, end(a));

	cout << endl << "30�����" << endl;
	copy(begin(a), begin(a) + 30, ostream_iterator<int>(cout, "\t"));
	cout << endl << "������" << endl;
	copy(begin(a) + 30, end(a), ostream_iterator<int>(cout, "\t"));


	// ��ü�� ������ �� - sort
	sort(begin(a), end(a));
	cout << endl << "�������� ���� ��" << endl;
	copy(begin(a), end(a), ostream_iterator<int>(cout, "\t"));

}