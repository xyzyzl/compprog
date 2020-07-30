#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, pos = 0;
	int lo = 0, hi = 0;
	stack<pair<int, int> > cur;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x;
		char dir;
		cin >> x >> dir;
		int pre = pos;
		if(dir == 'L') pos -= x;
		else           pos += x;

		if(pre >= 0 && dir == 'L')
		{
			while(cur.size() && cur.top().first >= pos) cur.pop();
			if(cur.size()) cur.top().second = min(cur.top().second, pos);
		}
		else if(pre <= 0 && dir == 'R')
		{
			while(cur.size() && cur.top().second <= pos) cur.pop();
			if(cur.size()) cur.top().first  = max(cur.top().first , pos);
		}
		if(pos > hi)
		{
			cur.push(make_pair(hi, pos));
			hi = pos;
		} else if(pos < lo)
		{
			cur.push(make_pair(pos, lo));
			lo = pos;
		}
	}
	int tot = hi - lo;
	while(!cur.empty())
	{
		tot -= (cur.top().second - cur.top().first);
		cur.pop();
	}
	cout << tot << endl;
}
