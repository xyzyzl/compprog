#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

const int MAXN = 200005;
const int INF = 1e9+7;

int n, q, S[MAXN], F[MAXN], nuke=1;
using pii = pair<int, int>;
using ll = long long;
#define f first
#define s second

ll st[8*MAXN], lz[8*MAXN];

void build(int nd, int i, int j)
{
	if(i == j)
	{
		st[nd] = F[i];
		return;
	}
	int d = (i+j)/2;
	build( 2 * nd    , i  , d);
	build( 2 * nd + 1, d+1, j);
	st[nd] = st[2*nd] + st[2*nd+1];
}

void upd(int nd, int i, int j, int l, int r, ll v)
{
	if(lz[nd] != -1)
	{
		st[nd] += (j-i+1)*lz[nd];
		lz[2*nd] = lz[2*nd+1] = lz[nd];
		lz[nd] = -1;
	}
	if(i > r || j < l) return; // not in range
	if(i >= l && j <= r) // completely in range
	{
		st[nd] = v*(j-i+1);
		lz[2*nd] = lz[2*nd+1] = v;
		return;
	}
	int d = (i+j)/2;
	upd( 2 * nd    , i  , d, l, r, v);
	upd( 2 * nd + 1, d+1, j, l, r, v);
	st[nd] = st[2 * nd] + st[2 * nd + 1];
}

ll rsq(int nd, int i, int j, int l, int r)
{
	if(lz[nd] != -1)
	{
		st[nd] = (j-i+1)*lz[nd];
		lz[2*nd] = lz[2*nd+1] = lz[nd];
		lz[nd] = -1;
	}
	if(i > r || j < l) return 0;
	if(i >= l && j <= r) return st[nd];
	int d = (i+j)/2;
	int p = rsq( 2 * nd    , i  , d, l, r);
	int q = rsq( 2 * nd + 1, d+1, j, l, r);
	return p+q;
}

vector<pii> v;
void solve()
{
	cin >> n >> q;
	for(int i = 0; i < 8*n; i++)
	{
		st[i] = 0;
		lz[i] = -1;
	}
	nuke = 1;
	while(nuke < n) nuke *= 2;
	for(int i = 0; i < n; i++) 
	{
		char c; cin >> c; S[i] = (c=='1');
	}
	for(int i = 0; i < n; i++) 
	{
		char c; cin >> c; F[i] = (c=='1');
	}
	v.clear();
	for(int i = 0; i < q; i++)
	{
		int l, r; cin >> l >> r; --l; --r;
		v.push_back({l, r});
	}
	build(1, 0, n-1);
	reverse(v.begin(), v.end());
	for(int i = 0; i < q; i++)
	{
		int siz = (v[i].s-v[i].f+1);
		ll sm = rsq(1, 0, n-1, v[i].f, v[i].s);
		if(sm < siz-sm)
		{
			upd(1, 0, n-1, v[i].f, v[i].s, 0);
		}
		else if(sm > siz-sm)
		{
			upd(1, 0, n-1, v[i].f, v[i].s, 1);
		}
		else
		{
			cout << "NO" << endl;
			return;
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(rsq(1, 0, n-1, i, i) != S[i])
		{
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
}
