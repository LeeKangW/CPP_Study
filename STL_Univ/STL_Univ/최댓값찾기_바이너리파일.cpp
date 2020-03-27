#include"default.h"
#include<fstream>
#include<limits>

int main() {
	ifstream in("정수 1000개.txt", ios::binary);

	int n;
	int max{ numeric_limits<int>::min() }; // 가장 작은 값으로 설정

	for (int i = 0; i < 1'000; ++i) {
		in.read((char*)&n, sizeof(n));
		if (max < n)
			max = n;
	}
	
	cout << "\"정수 1000개.txt\"에 저장된 int 중 가장 큰 값은 " << max << endl;

}