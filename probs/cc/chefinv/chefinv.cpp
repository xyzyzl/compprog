#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;
using ll = long long;
#define int ll
using pii = pair<int, int>;
#define bitinc(x) (x&-x)
#define f first
#define s second
#define pb push_back
int n, n2, m, a[MAXN];
vector<pii> P[MAXN], S[MAXN];

ll ad = 0, ans[MAXN]; // ad = # of inversions initially, ans[i] if we take this case

struct BIT
{
	int n, bit[2*MAXN];
	BIT(int n)
	{
		this->n = n;
	}
	int sum(int ind)
	{
		int sm = 0;
		while (ind > 0)
		{
			sm += bit[ind];
			ind -= bitinc(ind);
		}
		return sm;
	}
	void upd(int ind, int val)
	{
		while (ind <= n)
		{
			bit[ind] += val;
			ind += bitinc(ind);
		}
	}
} og(4);

int bit[2*MAXN]; // this one needs two-sided operations, which the above BIT code can't do...

void pupd(int ind, int val)
{
	while(ind > 0)
	{
		bit[ind] += val;
		ind -= bitinc(ind);
	}
}

int psum(int ind)
{
	if(ind == 0) return 0;
	int sm = 0;
	while(ind <= n2)
	{
		sm += bit[ind];
		ind += bitinc(ind);
	}
	return sm;
}

void supd(int ind, int val)
{
	if(ind == 0) return;
	while(ind <= n2)
	{
		bit[ind] += val;
		ind += bitinc(ind);
	}
}

int ssum(int ind)
{
	int sm = 0;
	while(ind > 0)
	{
		sm += bit[ind];
		ind -= bitinc(ind);
	}
	return sm;
}

void pre()
{
	for(int i = 1; i <= n; i++)
	{
		pupd(a[i], 1);
		for(int q = 0; q < P[i].size(); q++)
		{
			ans[abs(P[i][q].s)] += (P[i][q].s < 0 ? -1 : 1) * psum(P[i][q].f);
		}
	}
}

void suf()
{
	for(int i = n; i >= 1; i--)
	{
		supd(a[i], 1);
		for(int q = 0; q < S[i].size(); q++)
		{
			ans[abs(S[i][q].s)] += (S[i][q].s < 0 ? -1 : 1) * ssum(S[i][q].f);
		}
	}
}

signed main()
{
	cin >> n >> m;
	og=BIT(n);
	set<int> b;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b.insert(a[i]);
	}
	n2 = b.size();
	vector<int> b2;
	for (int x : b) b2.pb(x);
	for (int i = 1; i <= n; i++)
	{
		a[i] = lower_bound(b2.begin(), b2.end(), a[i]) - b2.begin() + 1;
	}
	for (int i = 1; i <= m; i++)
	{
		int l, r;
		cin >> l >> r;
		if (l > r)
			swap(l, r);
		if(a[l] != a[r]) ans[i]++;

		P[l-1].pb({a[l]+1, -i});
		P[r-1].pb({a[r]+1, -i});
		S[l+1].pb({a[l]-1, -i});
		S[r+1].pb({a[r]-1, -i});

		P[l-1].pb({a[r]+1, +i});
		P[r-1].pb({a[l]+1, +i});
		S[l+1].pb({a[r]-1, +i});
		S[r+1].pb({a[l]-1, +i});
	}
	for (int i = 1; i <= n; i++)
	{
		ad += i-1;
		ad -= og.sum(a[i]);
		og.upd(a[i], 1);
	}
	// cerr << ad << endl; // original sum of number of inversions
	pre();
	memset(bit, 0, sizeof bit);
	suf();
	for(int i = 1; i <= m; i++)
	{
		cout << ad+ans[i] << endl;
	}
}