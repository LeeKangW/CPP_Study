#include"default.h"
#include"String.h"
#include<algorithm>


int main() {
	String str{ "The quick brown fox jumps over the lazy dog" };
	auto [min, max] = minmax_element(str.begin(), str.end());

	cout << "�ּ�: " << *min << ", �ִ�: " << *max << endl;
}