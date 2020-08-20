// Time:
// Algorithms:

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
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL);                \
	cout.tie(NULL)

#define fileio(in, out)      \
	freopen(in, "r", stdin); \
	freopen(out, "w", stdout);

#define ll long long
// overflow lazy fix
#define int ll
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

int n, m[MAXN], pre[MAXN], nxt[MAXN];
ll dp[2][MAXN];
void solve()
{
	cin >> n;
	F1R(i, n)
		cin >> m[i];
	// find minima via stack
	stack<ll> st;
	st.push(1);
	pre[1] = 0;
	// find everything from previous
	FORR(2, i, n + 1)
	{
		// remove elements that are too large
		while (!st.empty() && m[st.top()] >= m[i])
			st.pop();
		// add next smallest element
		if (st.empty())
			pre[i] = 0;
		else
			pre[i] = st.top();
		// add current element too
		st.push(i);
	}
	// clear stack
	while (!st.empty())
		st.pop();
	// repeat same for nxt
	st.push(n);
	nxt[n] = n + 1;
	F1RD(i, n - 1)
	{
		while (!st.empty() && m[st.top()] >= m[i])
			st.pop();
		if (st.empty())
			nxt[i] = n + 1;
		else
			nxt[i] = st.top();
		st.push(i);
	}
	// max. number of stories going from left
	dp[0][0] = 0;
	F1R(i, n)
	{
		// check previous building shorter than current
		dp[0][i] = dp[0][pre[i]] + (i - pre[i]) * m[i];
	}
	// max. number of stories going to right
	dp[1][n + 1] = 0;
	F1RD(i, n)
	{
		dp[1][i] = dp[1][nxt[i]] + (nxt[i] - i) * m[i];
	}
	int val = 0;
	ll mx = 0;
	// find peak from these maxima
	FOR(i, n + 1)
	{
		if (dp[0][i] + dp[1][i + 1] > mx)
		{
			mx = dp[0][i] + dp[1][i + 1];
			val = i+1;
		}
	}
	// do same operation as C1 with this fixed peak
	int lf = m[val], rg = m[val];
	vi v(n);
	FORD(i, val)
	{
		MIN(lf, m[i+1]);
		v[i] = lf;
	}
	FORR(val, i, n)
	{
		MIN(rg, m[i+1]);
		v[i] = rg;
	}
	for(int x : v) cout << x << " ";
	cout << endl;
}

signed main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while (t--)
	{
		solve();
	}
}
