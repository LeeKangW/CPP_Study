#include<iostream>
#include<algorithm>
#include<fstream>
#include<random>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;

int main() {
	ifstream in("정수1000만개.data", ios::binary);

	vector<int> data(1000'0000);

	cout << "데이터 삽입 시작" << endl;
	for (int i = 0; i < 1000'0000; ++i) {
		in.read((char*)&data[i], sizeof(data[i]));
	}
	cout << "데이터 삽입 끝" << endl << endl;

	
	cout << "정렬 시작" << endl;
	sort(begin(data), end(data), [](int a, int b) {
		return a < b;
		});
	cout << "정렬 끝" << endl << endl;

	ofstream out("정수1000만개정렬.data",ios::binary);
	cout << "정렬 값 저장 시작" << endl;
	for (int n : data) {
		out.write((char*)&n, sizeof(n));
	}
	cout << "정렬 값 저장 완료" << endl;

	//for (int n : data)
	//	cout << setw(20) << left << n;
}