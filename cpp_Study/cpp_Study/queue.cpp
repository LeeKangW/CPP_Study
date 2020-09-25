#include<iostream>
#include<queue>

using namespace std;

struct Comp
{
	bool operator()(pair<int, string> a, pair<int, string> b)
	{
		return a.second < b.second;
	}
};

int main()
{
	queue<int> q;
	q.push(3);
	q.push(4);
	q.push(5);
	
	while (!q.empty())
	{
		cout << q.front() << ", ";
		q.pop();
	}
	cout << endl;

	priority_queue<pair<int, string>,vector<pair<int,string>>,Comp> pq;

	pq.push(make_pair(1, "��"));
	pq.push(make_pair(2, "��"));
	pq.push(make_pair(3, "��"));
	pq.push(make_pair(4, "��"));
	pq.push(make_pair(5, "��"));

	while (!pq.empty())
	{
		cout << pq.top().second << " / ";
		pq.pop();
	}
}