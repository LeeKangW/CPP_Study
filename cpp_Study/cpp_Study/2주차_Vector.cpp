#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
	vector<int> v{ 1,2,3,4,5,6 };
	vector<int> v2{ 1,2,3,4,5,6 };

	
	copy(istream_iterator<int,char>(cin), istream_iterator<int, char>(), back_inserter(v2));
	//copy(v2.begin(), v2.end(), ostream_iterator<int>(cout),v2.begin());
}