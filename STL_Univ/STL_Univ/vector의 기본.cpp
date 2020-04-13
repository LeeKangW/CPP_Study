#include"default.h"
#include<vector>

int main() {

	vector<int> v{ 1,2,3,4,5 };

	cout << "벡터 객체의 크기 - " << sizeof(v) << endl;
	cout << "벡터의 원소 수 -" << v.size() << endl;
	cout << "현재 벡터가 담을 수 있는 원소의 갯수 -" << v.capacity() << endl;
	cout << "이 시스템에서 vector<int>가 담을 수 있는 최대 원소 수 -" << v.max_size() << endl;

	cout << endl;

	cout << "벡터에 들어있는 원소들" << endl;
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	v.push_back(6); // 원소 1개 추가

	cout << endl;

	cout << "벡터 객체의 크기 - " << sizeof(v) << endl;
	cout << "벡터의 원소 수 -" << v.size() << endl;
	cout << "현재 벡터가 담을 수 있는 원소의 갯수 -" << v.capacity() << endl;
	cout << "이 시스템에서 vector<int>가 담을 수 있는 최대 원소 수 -" << v.max_size() << endl;

	cout << endl;

	cout << "벡터에 들어있는 원소들" << endl;
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}