#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>
using namespace std;

int main() {	
	string s;
	cout << "단어를 마음 껏 입력하세요. 끝내시려면 ctrl+z" << endl;

	vector<string> v{ istream_iterator<string>(cin), istream_iterator<string>() };
	cout << endl;
	sort(begin(v), end(v));
	copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\t"));


}