#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string file{ "STL Wiki.txt" };

int main() {
	ifstream in(file);
	ofstream out("STL Wiki �빮��.txt");

	if (!in)
		cout << file << "�������� ����" << endl;

	int c;

	while ((c = in.get()) != EOF) {
		cout <<(char)c;
		out << (char)c;
	}
	
}