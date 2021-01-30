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
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<pii, int> iii;
typedef vector<pii> vii;
typedef vector<iii> viii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
// ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> osii;
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

void solve()
{
	int n, b;
	cin >> n >> b;
	vi a(n), c(n), e(b);
	vii d(b);
	FOR(i, n)
	{
		cin >> a[i];
		c[i] = i;
	}
	// may also be able to use pbds OST instead of a two-pointer? will look into later
	// but this works for now
	sort(c.begin(), c.end(), [&a](const int& p, const int& q) { return a[p] < a[q]; });
	FOR(i, b)
	{
		cin >> d[i].f >> d[i].s;
		e[i] = i;
	}
	sort(e.begin(), e.end(), [&d](const int& p, const int& q) { return d[p] < d[q]; });
	vi pr(n), nx(n);
	FOR(i, n) 
	{
		pr[i] = i-1;
		nx[i] = i+1;
	}
	int k = n-1, mx = 1;
	vi ans(b);
	FORD(i, b)
	{
		while(a[c[k]] > d[e[i]].f)
		{
			// erase current index
			int pt = c[k];
			if(pr[pt] >= 0) nx[pr[pt]] = nx[pt];
			if(nx[pt] <  n) pr[nx[pt]] = pr[pt];
			MAX(mx, nx[pt] - pr[pt]);
			k--;
		}
		ans[e[i]] = mx <= d[e[i]].s;
	}
	FOR(i, b) cout << ans[i] << endl;
}

signed main()
{
	fileio("snowboots");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
