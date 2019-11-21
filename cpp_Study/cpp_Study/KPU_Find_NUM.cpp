#include<iostream>
#include<vector>

using namespace std;
void Check_S(vector<int> num) {
	int C_S = num[0];
	int S_K = num[2];

	int
		x = 0,
		y = 0,
		z = 0;
	
	x = C_S - (y + z);
	y = C_S - (x + z);
	z = C_S - (y + z);
	for (int i = 0; i < S_K; i++) {

	}
}
void Check_P(vector<int> num) {

}
int main() {
	int
		S = 0,
		P = 0,
		k = 0;

	char c_input[3];
	vector<int> input;
	cin.getline(c_input, 4);

	for (int i = 0; i < 3; i++) {
		input.push_back(int(c_input[i])-'0');
	}

	
	
}