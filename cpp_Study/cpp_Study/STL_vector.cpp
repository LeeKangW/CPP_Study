#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> v = { 1,2,3,4,5 };

	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << ' ';

	}
	cout << endl;

	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << (it - v.begin()) << ": " << *it << endl;
	}

	cout << v.data(3) << endl;
}