#include"default.h"
#include<random>
#include<algorithm>
#include<array>
#include<fstream>

void find_max(array<int, 1000> arr);

int main() {
	
	
#pragma region 실습 1 최대값 찾기.
	ifstream in("정수1000개.txt");
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

#pragma region 실습 2 파일크기 확인 변수

	ifstream in2("정수1000개.txt", ios::binary);

	size_t length;
	char* buffer;
	
	// get length of file
	in2.seekg(0, ios::end);
	length = in2.tellg();
	
	in2.close();

	cout << "파일 크기 : " << length << endl;
	
#pragma endregion

}
void find_max(array<int, 1000> arr) {

	sort(arr.begin(), arr.end());

	cout << "정수 1000개 중 최댓값 : " << arr.at(arr.size()-1) << endl;
}


