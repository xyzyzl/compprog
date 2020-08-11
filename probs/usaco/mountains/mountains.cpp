#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> x, pair<int, int> y)
{
	if(x.first == y.first)
	{
		return x.second > y.second;
	}
	return x.first < y.first;
}

int main()
{
	freopen("mountains.in", "r", stdin);
	freopen("mountains.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int, int> > ev;
	for(int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		ev.push_back({x-y,x+y});
	}
	sort(ev.begin(), ev.end(), comp);
	int ct = 0, mxx = -1;
	for(int i = 0; i < n; i++)
	{
		if(ev[i].second > mxx)
		{
			ct++;
			mxx = ev[i].second;
		}
	}
	cout << ct << endl;
}
