#include"default.h"
#include<vector>

int main() {
	vector<int> v{ 1,2,3,4 };
	
	cout << "vector v�� �ּ� :" << &v << endl;

	cout << "������ ����: " << v.size() << endl;
	cout << "���Ұ� ����� �޸�:" << v.data() << endl;
	cout << "���Ҵ����� �ʰ� ���� �� �ִ� ����:" << v.capacity() << endl;

	// 777�� �߰��մϴ�.
	v.push_back(777);

	cout << endl << "---------���� �߰� �� ----" << endl;

	cout << "vector v�� �ּ� :" << &v << endl;

	cout << "������ ����: " << v.size() << endl;
	cout << "���Ұ� ����� �޸�:" << v.data() << endl;
	cout << "���Ҵ����� �ʰ� ���� �� �ִ� ����:" << v.capacity() << endl;

}