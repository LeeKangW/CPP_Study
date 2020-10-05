#include <iostream>
#include <vector>
#include <string>

using namespace std;

void VectorSort(vector<char>& v)
{
	for (vector<char>::iterator it = v.begin(); it != v.end() - 1; ++it)
	{
		int num1 = *it;
		int num2 = *(it + 1);

		if (num1 > num2)
		{
			int swp = num1;
			*(it) = num2;
			*(it + 1) = num1;
		}
	}
}

void CheckAllSort(vector<bool>& v, bool& isAllSort)
{
	// 전부다 정렬이 되었는지 확인용
	for (int i = 0; i < v.size(); ++i)
	{
		if (!v[i])
		{
			isAllSort = false;
			break;
		}
		else
		{
			isAllSort = true;
		}
	}
}

int main()
{
	string input = "";

	cin >> input;

	vector<char> v;

	for (int i = 0; i < input.size(); ++i)
	{
		v.push_back(input[i]);
	}

	vector<bool> v_tmp(v.size(), false);
	int v_tmpIdx = 0;

	bool isAllSort = false;

	while (!isAllSort)
	{
		VectorSort(v);

		v_tmp[v_tmpIdx++] = true;

		CheckAllSort(v_tmp, isAllSort);
	}

	cout << "===========================" << endl;

	for (char n : v)
		cout << n << endl;
}