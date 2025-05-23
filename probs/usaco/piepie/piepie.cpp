#include <bits/stdc++.h>

using namespace std;

int n, D, d[200005];
typedef pair<int, int> pii;
#define f first
#define s second
pii a[200005];

multiset<pii> mB, mE;
int main()
{
	freopen("piepie.in", "r", stdin);
	freopen("piepie.out", "w", stdout);
	cin >> n >> D;
	for(int i = 0; i < 2*n; i++)
	{
		// taste to Bessie and Elsie
		cin >> a[i].f >> a[i].s;
		a[i].f = -a[i].f;
		a[i].s = -a[i].s;
	}
	// bfs queue. put 0's as sources and dfs as needed
	queue<int> q;
	for(int i = 0; i < n; i++)
	{
		if(a[i].s == 0) // gift elsie 0 pie 
		{
			d[i] = 1;
			q.push(i);
		} else 
		{
			d[i] = -1;
			mB.insert(make_pair(a[i].s, i));
		}

		if(a[n+i].f == 0) // gift bessie 0 pie
		{
			d[n+i] = 1;
			q.push(n+i);
		} else
		{
			d[n+i] = -1;
			mE.insert(make_pair(a[n+i].f, n+i));
		}
	}
	auto x = mE.begin();
	auto y = mB.begin();
	while(!q.empty())
	{
		int tp = q.front();
		q.pop();
		if(tp < n) while(true)
		{ // bessie gives elsie pie
			x = mE.lower_bound(make_pair(a[tp].f, -1));
			if(x == mE.end() || a[x->s].f > a[tp].f+D) break;
			d[x->s] = d[tp]+1;
			q.push(x->s);
			mE.erase(x);
		} else while(true)
		{ // elsie gives bessie pie
			y = mB.lower_bound(make_pair(a[tp].s, -1));
			if(y == mB.end() || a[y->s].s > a[tp].s+D) break;
			d[y->s] = d[tp]+1;
			q.push(y->s);
			mB.erase(y);
		}
	}
	for(int i = 0; i < n; i++)
	{
		cout << d[i] << endl;
	}
}

