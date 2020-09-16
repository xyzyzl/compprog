
// Time:
// Algorithms: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 200005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define F1R(i, n) for (int i = 1; i <= n; i++)
#define F1RD(i, n) for (int i = n; i >= 1; i--)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL);                \
	cout.tie(NULL)

#define fileio(in, out)      \
	freopen(in, "r", stdin); \
	freopen(out, "w", stdout);

#define ll long long
#define MOD (1e9*1)+7
#define MOD2 998244353
#define INF (1e9*1)+5

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> iii;
typedef vector<pii> vii;
typedef vector<iii> viii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
// ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;
#define f first
#define s second

#define LEFT(x) 2 * x
#define RIGHT(x) 2 * x + 1

#define bitinc(x) x&-x

const int MAX(int &a, int b)
{
	return a = max(a, b); 
}
const int MIN(int &a, int b)
{
	return a = min(a, b); 
}

int n,q;
ll a[MAXN],d[MAXN];
void solve()
{
	cin >> n;
	FOR(i, n) cin >> a[i];
	cin >> q;
	FOR(i, n-1) d[i] = a[i+1]-a[i];
	ll sm = 0;
	FOR(i, n-1)
	{
		sm += max(d[i],0ll);
	}
	cout << (ll)ceil((double)(a[0]+sm)/2.0) << endl;
	FOR(i, q)
	{
		int l,r;
		ll x;
		cin >> l >> r >> x;
		--l; --r;
		if(l)
		{
			if(d[l-1] > 0) sm-=d[l-1];
			d[l-1]+=x;
			if(d[l-1] > 0) sm+=d[l-1];
		} else a[0] += x;
		if(r<n-1)
		{
			if(d[r] > 0) sm-=d[r];
			d[r]-=x;
			if(d[r] > 0) sm+=d[r];
		}
		cout << (ll)ceil((double)(a[0]+sm)/2.0) << endl;
	}
}

signed main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
