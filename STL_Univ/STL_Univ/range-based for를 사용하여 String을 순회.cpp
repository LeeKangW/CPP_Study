#include"default.h"
#include"String.h"

int main() {
	String str{ "The quick brown fox jumps over the lazy dog" };

	for (char c : str)
		cout << c << ' ';
	cout << endl;
}