#include"default.h"
#include"String.h"
#include<algorithm>
#include<iterator>
#include<vector>


template<class InIter, class OutIter>
OutIter my_copy(InIter first, InIter last, OutIter result);

int main()
{
	String str{ "The quick brown fox jumps over the lazy dog" };

	vector<char> v;
	v.reserve(str.size());

	my_copy(str.begin(), str.end(), back_inserter(v));

	for (int i = 0; i < str.size(); ++i)
		cout << v[i] << '~';
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