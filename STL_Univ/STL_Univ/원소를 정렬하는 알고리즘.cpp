#include<iostream>
#include<numeric>
#include<algorithm>
#include<iterator>
#include<random>

using namespace std;

// 정렬 관련 알고리즘 복잡도 낮은 것 --> 복잡도가 높은 것
// partition -> nth_element -> partial_sort -> sort -> stable_sort

int main() {

	int a[100];										// 정수 100개 준비
	iota(begin(a), end(a), 1);						// [1,100] 채운다.

	copy(begin(a), end(a), ostream_iterator<int>(cout, "\t"));

	mt19937 dre;
	shuffle(begin(a), end(a), dre);

	cout << endl << "데이터를 섞음" << endl;
	copy(begin(a), end(a), ostream_iterator<int>(cout, "\t"));

// Q1. 홀수와 짝수로 분리하여 각각 출력하라. - partition
	auto it = partition(begin(a), end(a), [](const int a) {
			return a & 1;
			});
	cout << endl << "홀수" << endl;
	copy(begin(a), it, ostream_iterator<int>(cout, "\t"));
	cout << endl << "짝수" << endl;
	copy(it, end(a), ostream_iterator<int>(cout, "\t"));

// [문제] 1등부터 30등까지 순서대로 뽑아줘 - partial_sort

	partial_sort(begin(a), begin(a) + 30, end(a));

	cout << endl << "30등까지" << endl;
	copy(begin(a), begin(a) + 30, ostream_iterator<int>(cout, "\t"));
	cout << endl << "나머지" << endl;
	copy(begin(a) + 30, end(a), ostream_iterator<int>(cout, "\t"));


	// 전체를 정렬해 줘 - sort
	sort(begin(a), end(a));
	cout << endl << "오름차순 정렬 후" << endl;
	copy(begin(a), end(a), ostream_iterator<int>(cout, "\t"));

}