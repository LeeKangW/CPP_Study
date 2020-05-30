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

// 10'000'000개의 정수를 만든다.[0 ~ 10'000'000] - 정규분포
// 1'000'000개의 찾을 정수를 만든다.[0 ~ 1'000'000] - 유니폼 분포 

// 천만개 정수를 각 컨테이너에 넣는다.
// 벡터
// 셋
// 언오더드 셋

// 100만개 정수를 찾는데 걸리는 시간을 재본다. - 금요일에

const int NUM{ 100'0000 };
const int TNUM{ 1'0000 };
int tnum[TNUM];
int main()
{
	// 정규분포를 갖는 정수 생성
	// normal_distribution<> nd{ 평균, 분산 };
	// 범위 : -5 ~ +5
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

	cout << "벡터 size() - " << v.size() << endl;

	/*
	auto res = all_of(v.begin(), v.end(), [](int n) {
		// all_of -> 전체가 구성된 것을 확인
		return 0 <= n || n <= 1000'0000;
		});

	if (res == true)
		cout << "모든 원소값이 정상" << endl;
	*/
#pragma region 1000'0000개의 벡터에서 원하는 값을 찾는다.
	/*
	if (find(v.begin(), v.end(), 333) != v.end())
		cout << "333을 찾음" << endl;
	else
		cout << "333은 없다." << endl;
	*/
#pragma endregion

#pragma region 1000'0000개의 벡터에서 원하는 값을 찾는데 걸리는 시간을 재본다.
	/* 원래 방법

	auto start = chrono::steady_clock::now();			// 시작 타임 포인트
	auto p = find(v.begin(), v.end(), 333);
	auto stop = chrono::steady_clock::now();			// 끝 타임 포인트
	auto elapsedTime = stop - start;
	auto d = chrono::duration_cast<chrono::milliseconds>(elapsedTime);
	cout << "경과시간 - " << d.count() << endl;

	*/

	/* 요약
	
	// using namespace chrono; -> chrono:: 을 지워서 더 줄일 수 있다.

	auto start = chrono::steady_clock::now();			// 시작 타임 포인트
	auto p = find(v.begin(), v.end(), 333);
	cout << "경과시간 - " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << endl;
	*/

#pragma region 정수 NUM 개에서 정수 TNUM개의 정수를 찾는다.
	
	// 찾으려는 값을 tnum[TNUM]에 저장한다.
	uniform_int_distribution<> uid{ 0,NUM - 1 };
	for (int i = 0; i < TNUM; ++i)
	{
		tnum[i] = v[uid(dre)];
	
	}
	

	// 벡터에서 정수 NUM개에서 원하는 정수 NUM개의 정수를 찾는다.
	// - O(n)
	{
		auto start = chrono::steady_clock::now();
		for (int i = 0; i < TNUM; ++i)
		{
			auto p = find(v.begin(), v.end(), tnum[i]);
		}
		cout << "경과시간 - " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << endl;
	}

	// 셋에서 정수 TNUM개의 정수를 찾는다.
	// - 0(long n)
	set<int> s{ v.begin(),v.end() };
	{
		auto start = chrono::steady_clock::now();
		for (int i = 0; i < TNUM; ++i)
		{
			auto p = s.find(tnum[i]);
		}
		cout << "경과시간 - " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << endl;
	}
#pragma endregion


}