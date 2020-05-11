#include <iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<iterator>
#include "String.h"
using namespace std;

// declaration
template <class InIter, class OutIter>
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
// definition
template <class InIter, class OutIter>
OutIter my_copy(InIter first, InIter last, OutIter result)
{
	while (first != last) {
		*result = *first;
		++result;
		++first;

	}return result;
}
