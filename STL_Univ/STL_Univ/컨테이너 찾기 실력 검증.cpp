#include<iostream>
#include<random>
#include<algorithm>
#include<vector>
#include<chrono>
#include<set>
#include<unordered_set>
#include"String.h"
#include"save.h"

using namespace std;

// 10'000'000���� ������ �����.[0 ~ 10'000'000] - ���Ժ���
// 1'000'000���� ã�� ������ �����.[0 ~ 1'000'000] - ������ ���� 

// õ���� ������ �� �����̳ʿ� �ִ´�.
// ����
// ��
// ������� ��

// 100���� ������ ã�µ� �ɸ��� �ð��� �纻��. - �ݿ��Ͽ�

const int NUM{ 100'0000 };
const int TNUM{ 1'0000 };
int tnum[TNUM];
int main()
{
	// ���Ժ����� ���� ���� ����
	// normal_distribution<> nd{ ���, �л� };
	// ���� : -5 ~ +5
	normal_distribution<> nd{ 0.0 , 1.0 };
	default_random_engine dre;

	vector<int> v;
	v.reserve(NUM);

	for (int i = 0; i < NUM; ++i) {
		double d = nd(dre);
		d = clamp(d, -5.0, 5.0);
		d += 5.0;			// 0 ~ 10
		d *= 100'0000;		// [0 ~ 1000'0000]

		v.push_back(d);

	}

	cout << "���� size() - " << v.size() << endl;

	/*
	auto res = all_of(v.begin(), v.end(), [](int n) {
		// all_of -> ��ü�� ������ ���� Ȯ��
		return 0 <= n || n <= 1000'0000;
		});

	if (res == true)
		cout << "��� ���Ұ��� ����" << endl;
	*/
#pragma region 1000'0000���� ���Ϳ��� ���ϴ� ���� ã�´�.
	/*
	if (find(v.begin(), v.end(), 333) != v.end())
		cout << "333�� ã��" << endl;
	else
		cout << "333�� ����." << endl;
	*/
#pragma endregion

#pragma region 1000'0000���� ���Ϳ��� ���ϴ� ���� ã�µ� �ɸ��� �ð��� �纻��.
	/* ���� ���

	auto start = chrono::steady_clock::now();			// ���� Ÿ�� ����Ʈ
	auto p = find(v.begin(), v.end(), 333);
	auto stop = chrono::steady_clock::now();			// �� Ÿ�� ����Ʈ
	auto elapsedTime = stop - start;
	auto d = chrono::duration_cast<chrono::milliseconds>(elapsedTime);
	cout << "����ð� - " << d.count() << endl;

	*/

	/* ���
	
	// using namespace chrono; -> chrono:: �� ������ �� ���� �� �ִ�.

	auto start = chrono::steady_clock::now();			// ���� Ÿ�� ����Ʈ
	auto p = find(v.begin(), v.end(), 333);
	cout << "����ð� - " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << endl;
	*/

#pragma region ���� NUM ������ ���� TNUM���� ������ ã�´�.
	
	// ã������ ���� tnum[TNUM]�� �����Ѵ�.
	uniform_int_distribution<> uid{ 0,NUM - 1 };
	for (int i = 0; i < TNUM; ++i)
	{
		tnum[i] = v[uid(dre)];
	
	}
	

	// ���Ϳ��� ���� NUM������ ���ϴ� ���� NUM���� ������ ã�´�.
	// - O(n)
	{
		auto start = chrono::steady_clock::now();
		for (int i = 0; i < TNUM; ++i)
		{
			auto p = find(v.begin(), v.end(), tnum[i]);
		}
		cout << "����ð� - " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << endl;
	}

	// �¿��� ���� TNUM���� ������ ã�´�.
	// - 0(long n)
	set<int> s{ v.begin(),v.end() };
	{
		auto start = chrono::steady_clock::now();
		for (int i = 0; i < TNUM; ++i)
		{
			auto p = s.find(tnum[i]);
		}
		cout << "����ð� - " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << endl;
	}
#pragma endregion


}