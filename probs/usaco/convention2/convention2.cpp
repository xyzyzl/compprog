#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n;
pair<ll, pair<ll, ll> > cows[100005];
int main()
{
	freopen("convention2.in","r",stdin);
	freopen("convention2.out","w",stdout);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		ll a, t;
		cin >> a >> t;
		cows[i] = make_pair(a, make_pair(-i, t));
	}
	sort(cows, cows+n);
	pair<ll, ll> cur; // (real start time, length)
	priority_queue<pair<ll, pair<ll, ll> > > q; // seniority, enter, length
	int nx = 0;
	ll mx = 0;
	while(nx < n || q.size() > 0)
	{
		while(nx < n && cows[nx].first <= cur.first + cur.second)
		{
			q.push(make_pair(cows[nx].second.first, 
						make_pair(cows[nx].first, cows[nx].second.second)));
			nx++;
		}
		if(q.empty() && nx < n)
		{
			// add first cow
			cur = make_pair(cows[nx].first, cows[nx].second.second);
			nx++;
		} else if(!q.empty())
		{
			// move cow from queue to cur
			ll nt = cur.first + cur.second;
			pair<ll, pair<ll, ll> > tp = q.top();
			q.pop();
			cur = make_pair(nt, tp.second.second);
			mx = max(mx, nt - tp.second.first);
		}
	}
	cout << mx << endl;
}
