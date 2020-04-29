#include"default.h"
#include"String.h"

int main() {
	String str{ "The quick brown fox jumps over the lazy dog" };

	for (auto i = str.rbegin(); i != str.rend(); ++i)
		cout << *i;
	cout << endl;
}