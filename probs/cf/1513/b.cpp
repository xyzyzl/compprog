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
#define MOD (int)((1e9*1)+7)
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

ll fact[MAXN];
void solve()
{
	ll ans = 0;
	int n; cin >> n;
	vi a(n);
	mii f;
	FOR(i, n)
	{
		cin >> a[i];
		f[a[i]]++;
	}
	sort(a.begin(), a.end());
	if(f[a[0]] < 2)
	{
		cout << 0 << endl;
		return;
	} else 
	{
		swap(a[1], a[n-1]);
		int pre = a[0];
		F1R(i, n-1)
		{
			pre = pre & a[i];
			if(pre != a[0])
			{
				cout << 0 << endl;
				return;
			}
		}
		int suf = a[n-1];
		FORD(i, n-1)
		{
			suf = suf & a[i];
			if(suf != a[n-1])
			{
				cout << 0 << endl;
				return;
			}
		}

		ll ct = f[a[0]];
		ll x = ct*(ct-1)%MOD;
		cout << ((x*fact[n-2])%MOD) << endl;
	}
}

signed main()
{
	fact[0] = 1;
	F1R(i, MAXN-1) fact[i] = (fact[i-1]*i)%MOD;
	// fileio("");
	DUEHOANG;
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
