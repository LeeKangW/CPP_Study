#include"default.h"
#include"String.h"
#include<algorithm>
#include<iterator>


template<class InIter,class OutIter>
OutIter my_copy(InIter first, InIter last, OutIter result);

int main() {
	char a[]{ '1','2','3','4','5' };
	char b[5];
	String str{ "The quick brown fox jumps over the lazy dog" };
	my_copy(str.begin(), str.end(), ostream_iterator<char>(cout, "*"));

	
	cout << endl;

	copy(begin(a), end(a), begin(b));

	for (char c : b)
		cout << c << "-";
	cout << endl;
}

template<class InIter, class OutIter>
OutIter my_copy(InIter first, InIter last, OutIter result) {
	
	while (first != last) {
		*result = *first;
		++first;
		++result;
	}
	return result; // 이어서 쓸 위치를 리턴.
}