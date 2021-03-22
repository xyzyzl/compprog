#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 500005

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

int n, m, a[MAXN], b[MAXN], id[2*MAXN];
ll num[MAXN];
ll k;

// this is my breaking point
ll amogus()
{
	ll x = 0, y = 0;
	int i = 0, j = 0;
	for(i=0; (i+m)%n; i=(i+m)%n)
	{
		// for each block of m:
		x += num[i]; // add the number of "bad" indices
		y += m; // add the number of total indices
	}
	// add another set
	x += num[i];
	y += m;
	ll ans = (k-1)/x*y;
	k -= (k-1)/x*x;
	for(i=0; k > num[i]; i=(i+m)%n)
	{
		k -= num[i];
		ans += m;
	}
	while(k)
	{
		if(a[i] != b[j]) --k;
		ans++;
		i=(i+1)%n;
		j++;
	}
	return ans;
}

void solve()
{
	memset(id, -1, sizeof id);
	cin >> n >> m >> k;
	FOR(i, n)
	{
		cin >> a[i];
		id[a[i]] = i;
		num[i] = m;
	}
	FOR(i, m)
	{
		cin >> b[i];
		if(id[b[i]]<0) continue;
		--num[((id[b[i]]-i)%n+n)%n];
	}
	cout << amogus() << endl;
}

signed main()
{
	// fileio("");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
