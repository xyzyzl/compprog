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
#define ins insert
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL);                \
	cout.tie(NULL)
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define ll long long
#define MOD ((1e9*1)+7)
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

typedef set<ll> sl;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> lll;
typedef vector<pll> vll;
typedef vector<lll> vlll;
typedef priority_queue<ll> pql;
typedef stack<ll> stl;
typedef queue<ll> ql;
typedef deque<ll> dl;
typedef map<ll, ll> mll;

// ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> osii;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> osll;
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

bool chk(ll x, int h, vl& a)
{
	int n = a.size();
	ll p = x/2 + (x%2&&h); // # 2's left
	ll q = x/2 + (x%2&&!h); // # 1's left
	vl diff(n);
	FOR(i, n) diff[i] = a[n-1]-a[i];
	FOR(i, n)
	{
		ll rp = min(diff[i]/2, p);
		p -= rp;
		diff[i] -= 2*rp;

		ll rq = min(diff[i], q);
		q -= rq;
		diff[i] -= rq;

		if(diff[i])
		{
			return 0;
		}
	}
	return 1;
}

void solve()
{
	int n; cin >> n;
	vl a(n);
	FOR(i, n)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll ans = LLONG_MAX;
	FOR(h, 2)
	{
		ll lo = 0, hi = 1e18, k = -1;
		while(lo <= hi)
		{
			ll mid = (lo+hi)/2;
			if(chk(mid, h, a))
			{
				k = mid;
				hi = mid-1;
			} else 
			{
				lo = mid+1;
			}
		}
		ans = min(k+h, ans);
		// cerr << k+h << " " << chk(2,h,a) << endl;
		a[n-1]++;
	}
	cout << ans << endl;
}

signed main()
{
	// fileio("");
	DUEHOANG;
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
