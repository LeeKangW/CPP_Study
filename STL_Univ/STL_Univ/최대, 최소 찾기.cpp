#include"default.h"
#include"String.h"
#include<vector>
#include<algorithm>

int main() {
	vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };

	/*
	pair<vector<int>::iterator, vector<int>::iterator> p
		= minmax_element(v.begin(), v.end());
	*/
	auto p = minmax_element(v.begin(), v.end());

	// C++ 17 추가된 기능
	auto [min, max] = minmax_element(v.begin(), v.end());
	cout << "최소: " << *p.first << ", 최대 : " << *p.second << endl;

	cout << endl << "C++17 추가된 기능" << endl;
	cout << "최소: " << *min << ", 최대 : " << *max << endl;
}