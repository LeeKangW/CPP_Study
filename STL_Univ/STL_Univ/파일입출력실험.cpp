#include <iostream>
#include <random>
#include <fstream>

using namespace std;

void makefile() {
	ofstream out("파일입출력실험.txt");

	int n{};
	for (int i = 0; i < 100; ++i) {
		n = i;
		out.write((char*)&n, sizeof(int));
		// out.write( reinterpret_cast<const char*>(&n), sizeof( n ) );
	}
}
int main() {
	makefile();

	ifstream in("파일입출력실험.txt");

	int num[100];
	in.read((char*)&num, sizeof(int) * 100);

	for (int n : num)
		cout << n << endl;

}