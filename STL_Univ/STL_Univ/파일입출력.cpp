#include"default.h"
#include<random>
#include<algorithm>
#include<array>
#include<fstream>

void find_max(array<int, 1000> arr);

int main() {
	
	
#pragma region �ǽ� 1 �ִ밪 ã��.
	ifstream in("����1000��.txt");
	int n{};
	int i{ 0 };

	array<int, 1000> arr{ 0, };


	while (in >> n) {
		arr[i] = n;
		cout << ++i << "-" << n << endl;
	}

	in.close();

	find_max(arr);

	
#pragma endregion	

#pragma region �ǽ� 2 ����ũ�� Ȯ�� ����

	ifstream in2("����1000��.txt", ios::binary);

	size_t length;
	char* buffer;
	
	// get length of file
	in2.seekg(0, ios::end);
	length = in2.tellg();
	
	in2.close();

	cout << "���� ũ�� : " << length << endl;
	
#pragma endregion

}
void find_max(array<int, 1000> arr) {

	sort(arr.begin(), arr.end());

	cout << "���� 1000�� �� �ִ� : " << arr.at(arr.size()-1) << endl;
}


