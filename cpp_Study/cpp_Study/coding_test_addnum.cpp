#include<iostream>
#include<vector>
using namespace std;

int main() {
	int count = 0;
	cin >> count;

	vector<int> vec;
	char* ch = new char[count];
	cin >> ch;

	for (int i = 0; i < count; i++) {
		vec.push_back(ch[i] -'0');
	}
	int num = 0;
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		num += *it;
	}
	cout << num;
	return 0;
}