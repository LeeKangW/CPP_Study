#include"default.h"
#include"String.h"
#include<algorithm>

int main() {
	String str{ "The quick brown fox jumps over the lazy dog" };

	sort(str.begin(), str.end());

	cout << str << endl;
}