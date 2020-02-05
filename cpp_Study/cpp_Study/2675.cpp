#include<iostream>
#include<string>
using namespace std;

int main() {

	int testcase_count = 0;
	cin >> testcase_count;

	int R = 0;
	string str;
	for (int i = 0; i < testcase_count; i++) {
		cin >> R >> str;
		for (int k = 0; k < str.length(); k++) {
			for (int l = 0; l < R; l++) {
				cout << str[k];
			}
		}
		cout << endl;
	}
}