#include<iostream>
#include<array>
#include<stdlib.h>
using namespace std;

void check(array<int, 5> num) {

	int check_num = 0;
	int same = 0;
	if (abs(num[0] - num[1]) == 1) {
		check_num += 1;
		for (int i = 2; i <= 5; i++) {
			if (i == 5 && same != 0) {
				check_num -= same;
				break;
			}
			if (abs(num[i - 1] - num[i]) == 1) {
				check_num += 1;
			}
			else if (num[i - 1] == num[i]) {
				check_num += 1;
				same += 1;
			}
			else if (abs(num[i - 1] - num[i]) != 1 && i < 4) {
				check_num -= 1;
			}
			
		}
	}
	else {
		for (int i = 1; i <= 5; i++) {
			if (i == 5 && same != 0) {
				check_num -= same;
				break;
			}
			else if (abs(num[i - 1] - num[i]) == 1) {
				check_num += 1;
			}
			else if (num[i - 1] == num[i]) {
				check_num += 1;
				same += 1;
			}
		}
	}
	if (check_num >= 3) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}

int main() {
	int num = 0;
	bool over = false;
	bool ex = false;
	char dicenum[11] = { 0, };
	array<int, 5> dice;
	
	while (!over) {
		cin.getline(dicenum, 11);
		for (int i = 0; i < 11; i++) {
			if (dicenum[i] != ' ') {
				if (num < 5) {
					dice[num] = (int)dicenum[i] - 48;
					if (dice[num] < 1 || 6 < dice[num] ) {
						over = true; ex = true;
						cout << "NO";
						break;
					}
					else {
						over = true;
					}
				}
				num++;
			}
		}
	}

	if(over && !ex)
		check(dice);
	return 0;

}