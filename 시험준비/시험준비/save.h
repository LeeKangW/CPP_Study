#pragma once
#include<fstream>
#include<string>

using namespace std;

void save(string file) {
	ifstream in(file);

	ofstream out(file + " ���� ����.txt");

	if (!in)
		return;

	char c;

	while ((c = in.get()) != EOF) {
		out << c;
	}
}