#include"default.h"
#include<fstream>
#include<string>
#include"String.h"

string file{ "STL Wiki.txt"s };
string out_file{ "STL Wiki���� e����.txt"s };
int main() {
	ifstream in(file);
	ofstream out(out_file);
	if (!in) {
		cout << file << "�� ����." << endl;
	}

	int c;

	while ((c=in.get())!=EOF)
	{
		if (c != 'e')
			out.put(c);
	}
}