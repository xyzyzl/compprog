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
#define MOD (1e9 * 1) + 7
#define MOD2 998244353
#define INF (1e9 * 1) + 5

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

#define bitinc(x) x & -x

const int MAX(int &a, int b)
{
	return a = max(a, b);
}
const int MIN(int &a, int b)
{
	return a = min(a, b);
}

int n, q;
vi v;
void ins(ll& ans, int i)
{
	if(i == 0 || i == n+1) return;
	if (v[i] > v[i - 1] && v[i + 1] <= v[i])
	{
		ans += v[i];
	}
	if (v[i] <= v[i - 1] && v[i + 1] > v[i])
	{
		ans -= v[i];
	}
}

void era(ll& ans, int i)
{
	if(i == 0 || i == n+1) return;
	if (v[i] > v[i - 1] && v[i + 1] <= v[i])
	{
		ans -= v[i];
	}
	if (v[i] <= v[i - 1] && v[i + 1] > v[i])
	{
		ans += v[i];
	}
}

void solve()
{
	cin >> n >> q;
	v.clear();
	v.resize(n+5);
	v[0] = 0;
	F1R(i, n)
	{
		cin >> v[i];
	}
	v[n + 1] = 0;
	ll ans = 0;
	F1R(i, n)
	{
		ins(ans, i);
	}
	cout << ans << endl;
	F1R(que, q)
	{
		int p, q;
		cin >> p >> q;
		era(ans, p-1);
		era(ans, p);
		era(ans, p+1);
		if(p != q)
		{
			if(q-1 != p && q-1 != p+1) era(ans, q-1);
			if(q != p+1) era(ans, q);
			era(ans, q+1);
		}
		swap(v[p], v[q]);
		ins(ans, p-1);
		ins(ans, p);
		ins(ans, p+1);
		if(p != q)
		{
			if(q-1 != p && q-1 != p+1) ins(ans, q-1);
			if(q != p+1) ins(ans, q);
			ins(ans, q+1);
		}
		cout << ans << endl;
	}
}

signed main()
{
	DUEHOANG;
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while (t--)
	{
		solve();
	}
}
