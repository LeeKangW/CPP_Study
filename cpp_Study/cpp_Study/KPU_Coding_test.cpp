#include<iostream>
#include<stdlib.h>
#include<array>
#include<vector>

/*
�־��� ������ �� ������ reverse�� ������ ���� ������ �� ������ ȸ��(Palindrome)�̶�� �մϴ�..���� ��� 79197 �� 324423�� Palindrome�Դϴ�.

���� N(1 �� N �� 1000000)�� �ϳ� �־�����, M�� �Ҽ�(prime number)�̰� Palindrome�̵Ǵ� ���� ���� ����M(M �� N)�� ã���ϴ�.

M�� N���� ũ�ų� �����ϴ�.

M�� �Ҽ�(prime number)�̹Ƿ� M�� 1�� M���θ� ������ �������� �մϴ�.

���� ���, N�� 31�̸� �� M�� 101�Դϴ�.


Input
�ϳ��� ���� N(1 �� N �� 1000000) �Է�


Output
����� N���� ũ�ų� ���� ���� �۰� �Ҽ� Palindrome�� �����ϴ� ���� M ���

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
			cout << "���� M ��� : ";
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
	
	cout << " ���� N �Է�: ";
	cin >> N;
	get_prime(N);

	return 0;
}