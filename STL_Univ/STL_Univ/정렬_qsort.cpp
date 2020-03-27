#include"default.h"
#include<fstream>
#include<iomanip>

int compareFunc(const void*, const void*);

int main() {
	ifstream in("정수 1000개.txt", ios::binary);

	int data[1'000];

	in.read((char*)&data, sizeof(int) * 1'000);
	// in.read(읽어들인 문자들을 저장할 문자 배열, 문자 몇 개를 읽을 것인지 )

	qsort(data, 1'000, sizeof(int), compareFunc);

	// 확인용 출력
	for (int n : data)
		cout << setw(20) << left << n;
	//setw(정수) : 정수만큼 띄어서 출력. 즉, 공백 생성

}

int compareFunc(const void* a, const void* b) {
	
	int num1 = *static_cast<const int*>(a);
	int num2 = *static_cast<const int*>(b);

	return num1 - num2;
}