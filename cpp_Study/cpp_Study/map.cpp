#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include<iostream>

using namespace std;
/*
string solution(vector<string> participant, vector<string> completion)
{
	
	map<string, int> m;

	for (const string& s : participant)
	{
		m[s] += 1;
	}

	for (const string& s : completion)
	{
		m[s] -= 1;
	}

	// 1¹ø
	for (map<string, int>::const_iterator it = m.begin(); it != m.end(); ++it)
	{
		if (it->second == 1)
			return it->first;
	}

	// 2¹ø
	for (const pair<string, int>& p : m)
	{
		if (p.second == 1)
			return p.first;
	}
}
*/
int main()
{
	multimap<string, int> mm;

	mm.insert(make_pair("mm", 3));
	mm.insert(make_pair("mm", 4));

	for (const pair<string, int>& p : mm)
	{
		cout << p.first << " / " << p.second << endl;
	}
}