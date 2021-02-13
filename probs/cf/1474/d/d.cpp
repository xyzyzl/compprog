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
#define MOD (1e9*1)+7
#define MOD2 998244353
#define INF (1e9*1)+5

typedef set<int> si;
typedef vector<ll> vi;
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

bool work(vi a)
{
	int n = a.size();
	for(int i = 0; i < n-1; i++)
	{
		if(a[i] > a[i+1]) return 0;
		a[i+1] -= a[i];
		a[i] = 0;
	}
	return (a[n-1] == 0);
}

void solve()
{
	int n; cin >> n; vi a(n);
	FOR(i, n) cin >> a[i];
	if(n==1)
	{
		cout << "NO" << endl;
		return;
	}
	if(work(a))
	{
		cout << "YES" << endl;
		return;
	}
	// try swapping the first and last
	swap(a[0], a[1]);
	if(work(a))
	{
		cout << "YES" << endl;
		return;
	}
	swap(a[0], a[1]);
	swap(a[n-1], a[n-2]);
	if(work(a))
	{
		cout << "YES" << endl;
		return;
	}
	swap(a[n-1], a[n-2]);
	vi pref(n), suf(n);
	vi ap = a;
	pref[0] = a[0];
	FOR(i, n-1) 
	{
		if(pref[i] == -1 || a[i] > a[i+1]) { pref[i+1] = -1; continue; }
		a[i+1] -= a[i];
		a[i] = 0;
		pref[i+1] = a[i+1];
	}
	a = ap;
	suf[n-1] = a[n-1];
	FORD(i, n-1) 
	{
		if(suf[i+1] == -1 || a[i+1] > a[i]) { suf[i] = -1; continue; }
		a[i] -= a[i+1];
		a[i+1] = 0;
		suf[i] = a[i];
	}
	a = ap;
	F1R(i, n-3)
	{
		vi K = {pref[i-1], a[i+1], a[i], suf[i+2]};
		if(pref[i-1] == -1 || suf[i+2] == -1) continue;
		if(work(K))
		{
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
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
