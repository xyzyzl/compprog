/**
 * Tags: DP
 * Let dp_i be the answer for up to the ith celeb and let ns_i be the maximum dp for the first i indices. 
 * Then a simple O(N^2) DP would be dp_i = sum for j from 1 to i-1 dp_j for all j such that it is possible to travel from 
 * j to i fast enough to catch both celebrities
 * 
 * One key observation to optimize this is that the maximum answer for anything greater that 2*r
 * celebrities before the current one is ns_i-2*r. Otherwise, we can do the recurrence described above in O(rn) time.
 * Because of the tiny constant factor, this is likely under the time limit.
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 100005

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

int r, n, dp[MAXN], ns[MAXN], ok[MAXN];
iii a[MAXN];

int dst(pii i, pii j)
{
	return abs(i.f - j.f) + abs(i.s - j.s);
}

void solve()
{
	cin >> r >> n;
	F1R(i, n)
	{
		cin >> a[i].f >> a[i].s.f >> a[i].s.s;
	}
	a[0].f = 0;
	a[0].s.f = 1;
	a[0].s.s = 1;
	F1R(i, n) dp[i] = -1;
	dp[0] = 0;
	ns[0] = 0;
	F1R(i, n)
	{
		F1R(j, min(i, 2*r))
		{
			if(i-j < 0) break;
			if(dp[i-j] >= 0 && a[i].f - a[i-j].f >= dst(a[i].s, a[i-j].s))
			{
				MAX(dp[i], dp[i-j]+1);
			}
		}
		if(i >= 2*r) MAX(dp[i], ns[i-2*r]+1);
		ns[i] = max(ns[i-1], dp[i]);
	}
	cout << ns[n] << endl;
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
