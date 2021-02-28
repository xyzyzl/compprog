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

int n, k, a[MAXN], fs[MAXN], vs[MAXN];
void solve()
{
	cin >> n >> k;
	stack<int> stk;
	memset(fs, -1, sizeof fs);
	FOR(i, n)
	{
		cin >> a[i];
	}
	FORD(i, n)
	{
		if(fs[a[i]] == -1) fs[a[i]] = i;
	}
	FOR(i, n)
	{
		if(a[i] > k || vs[a[i]]) continue;
		if(stk.empty())
		{
			stk.push(a[i]);
			vs[a[i]] = 1;
		} else
		{
			while(!stk.empty())
			{
				if(a[i] <= stk.top() && i < fs[stk.top()])
				{
					vs[stk.top()] = 0;
					stk.pop();
				}
				else break;
			}
			vs[a[i]] = 1;
			stk.push(a[i]);
		}
	}
	vi x;
	while(!stk.empty())
	{
		x.pb(stk.top());
		stk.pop();
	}
	reverse(x.begin(), x.end());
	for(int u : x) cout << u << " ";
	cout << endl;
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
