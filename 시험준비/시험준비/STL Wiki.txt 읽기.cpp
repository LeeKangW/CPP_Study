#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string file{ "STL Wiki.txt" };

int main() {
	ifstream in(file);
	ofstream out("STL Wiki 대문자.txt");

	if (!in)
		cout << file << "존재하지 않음" << endl;

	int c;

	while ((c = in.get()) != EOF) {
		cout <<(char)c;
		out << (char)c;
	}
	
}