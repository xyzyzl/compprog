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
#define int ll
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

bool comp(pii a, pii b)
{
	if(a.s == b.s) return a.f > b.f;
	return a.s < b.s;
}

void solve()
{
	int n, m; cin >> n >> m;
	vii v(n);
	vi b1, b2;
	FOR(i, n)
	{
		cin >> v[i].f;
	}
	FOR(i, n) 
	{
		cin >> v[i].s;
	}
	FOR(i, n)
	{
		if(v[i].s == 1) b1.pb(v[i].f);
		else b2.pb(v[i].f);
	}
	sort(b1.begin(), b1.end());
	reverse(b1.begin(), b1.end());
	sort(b2.begin(), b2.end());
	reverse(b2.begin(), b2.end());
	int a = b1.size(), b = b2.size();
	int s1 = 0;
	int s2 = 0;
	FOR(i, b) s2 += b2[i];
	int p2 = b;
	int ans = INT_MAX;
	FOR(p1, a+1)
	{
		while(p2 > 0 && s1 + s2 - b2[p2-1] >= m) 
		{
			p2--;
			s2-=b2[p2];
		}
		if(s1+s2 >= m)
		{
			MIN(ans, 2*p2+p1);
		}
		if(p1 != a) s1 += b1[p1];
	}
	cout << (ans == INT_MAX ? -1 : ans) << endl;
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
