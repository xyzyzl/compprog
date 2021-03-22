#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using pii=pair<int, int>;
#define f first
#define s second
const int MAXN = 200005;

int n, m, ctx[MAXN];
vector<int> has[MAXN];
pii	P[MAXN];
set<int> ix, iy;
map<int, int> xmap, ymap;

ll bit[2*MAXN];
ll sum(int ind)
{
	ll sm = 0;
	while(ind > 0)
	{
		sm += bit[ind];
		ind -= (ind&-ind);
	}
	return sm;
}

void upd(int ind, ll val)
{
	while(ind <= m)
	{
		bit[ind] += val;
		ind += (ind&-ind);
	}
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> P[i].f >> P[i].s;
		ix.insert(P[i].f);
		iy.insert(P[i].s);
	}
	int ct = 0;
	m = ix.size();
	for(int x : ix)
	{
		xmap[x] = ++ct;
		upd(ct, 1);
	}
	ct = 0;
	for(int y : iy)
	{
		ymap[y] = ++ct;
	}
	for(int i = 0; i < n; i++)
	{
		P[i].f = xmap[P[i].f];
		P[i].s = ymap[P[i].s];
		ctx[P[i].f]++;
		has[P[i].s].push_back(P[i].f);
	}
	ll ans = 0;
	for(int y = 1; y <= iy.size(); y++)
	{
		sort(has[y].begin(), has[y].end());
		// now i need to find the
		int pref = 1;
		for(auto x : has[y])
		{
			ans += (ll)(sum(x)-sum(pref-1))*(sum(m)-sum(x-1));
			pref = x+1;
			--ctx[x];
			if(!ctx[x])
			{
				upd(x, -1);
			}
		}
	}
	cout << ans << endl;
}