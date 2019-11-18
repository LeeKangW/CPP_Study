#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	pair<int, int> p;
	p = make_pair(10, 20);
	cout << p.first << " " << p.second << endl<<endl;

	pair<int, string> p2;
	p2 = make_pair(10, "출력결과 : ");
	cout << p2.second << p2.first << endl;
}