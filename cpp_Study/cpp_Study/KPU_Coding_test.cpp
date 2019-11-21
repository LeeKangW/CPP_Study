#include<iostream>
#include<stdlib.h>
#include<array>
#include<vector>

/*
주어진 정수와 그 정수를 reverse한 정수가 서로 같으면 그 정수는 회문(Palindrome)이라고 합니다..예를 들어 79197 및 324423은 Palindrome입니다.

정수 N(1 ≤ N ≤ 1000000)이 하나 주어지고, M이 소수(prime number)이고 Palindrome이되는 가장 작은 정수M(M ≥ N)을 찾습니다.

M은 N보다 크거나 같습니다.

M이 소수(prime number)이므로 M은 1과 M으로만 나누어 떨어져야 합니다.

예를 들어, N이 31이면 답 M은 101입니다.


Input
하나의 정수 N(1 ≤ N ≤ 1000000) 입력


Output
출력은 N보다 크거나 같은 가장 작고 소수 Palindrome을 만족하는 정수 M 출력

EX

Input = 31
output = 101
*/

using namespace std;

void sizeint(int N,vector<int>& arr) {
		for (int i = 0;; i++) {
			if (N / 10 <= 0) {
				arr.push_back(N);
				break;
			}
			arr.push_back(N % 10);
			N = N / 10;
		}
}

void get_prime(unsigned int num) {
	bool prime = false;
	bool fail = false;
	vector<int> arr_pirme;
	//array<int, 7> arr = { 0, };
	//array<int, 7> check_arr = { 0, };
	vector<int> arr;
	vector<int> check_arr;
	for (unsigned int i = num + 1; i <= 10000; i++) {
		for (unsigned int j = 2; j < i; j++) {
			if (i % j == 0) { prime = true; break; }
		}
		if (!prime) arr_pirme.push_back(i);
		else
			prime = false;
	}

	for (int i = 0; i < arr_pirme.size(); i++) {
		sizeint(arr_pirme[i], arr);
		check_arr.resize(arr.size());
		for (int i = 0; i < arr.size(); i++) {
			check_arr[(check_arr.size() - 1) - i] = arr[i];
		}
		
		for (int i =0 ;i<check_arr.size();i++){
			if (check_arr[i] != arr[i]) {
				fail = true;
				break;
			}
		}
		if (!fail) {
			cout << "정수 M 출력 : ";
			for (auto i = check_arr.begin();i!=check_arr.end(); i++) {
				cout<<*i;
			}
			cout << endl;
			break;
		}
		arr.clear();
		check_arr.clear();
		fail = false;
	}
}

int main() {
	unsigned int N = 0;
	
	cout << " 정수 N 입력: ";
	cin >> N;
	get_prime(N);

	return 0;
}