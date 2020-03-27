#include"default.h"
#include<random>
#include<fstream>


int main() {
	default_random_engine dre;
	uniform_int_distribution<int> uid;
	ofstream out("Á¤¼ö 1000°³.txt",ios::binary);

	int n;

	for (int i = 0; i < 1'000; i++) {
		n = uid(dre);
		out.write((char*)&n, sizeof(n));
		//out.write(reinterpret_cast<const char*>(&n),sizeof(n));
	}
}