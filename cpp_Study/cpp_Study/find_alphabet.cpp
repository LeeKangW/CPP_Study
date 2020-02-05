#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {

	string str;
	cin >> str;
	vector<int> save;
	bool found = false;

	for (int check = 'a'; check <= 'z';check++) {
		for (int i = 0; i < str.length(); i++) {
			if (check == (int)str[i]) {
				found = true;
				save.push_back(i);
				break;
			}
		}
		if (!found)
		{
			save.push_back(-1);
		}
		found = false;
	}

	for (auto i = save.begin(); i != save.end(); i++) {
		cout << *i << ' ';
	}
}