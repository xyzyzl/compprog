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

int n, a[MAXN], mt[MAXN], vis[MAXN];
void solve()
{
	cin >> n;
	FOR(i, n) cin >> a[i];
	vi v1, v2, v3;
	FORD(i, n)
	{
		if(a[i] == 0) continue;
		// is just 1
		if(a[i] == 1) v1.pb(i);
		// is 2
		else if(a[i] == 2)
		{
			if(v1.empty()) 
			{
				cout << -1 << endl;
				return;
			}
			v2.pb(i);
			mt[i] = v1.back();
			v1.pop_back();
		}
		// is 3
		else
		{
			if(v3.size())
			{
				mt[i] = v3.back();
			} else if(v2.size())
			{
				mt[i] = v2.back();
			} else if(v1.size())
			{
				mt[i] = v1.back();
				v1.pop_back();
			} else 
			{
				cout << -1 << endl;
				return;
			}
			v3.pb(i);
		}
	}
	vii ans;
	int r = 0;
	FOR(i, n)
	{
		if(vis[i] || !a[i]) continue;
		int cur = i;
		while(cur >= 0)
		{
			vis[cur] = 1;
			if(a[cur] == 1)
			{
				ans.pb(mp(r+1, cur+1));
				cur = -1;
				r++;
			} else if(a[cur] == 2)
			{
				ans.pb(mp(r+1, cur+1));
				cur = mt[cur];
			} else if(a[cur] == 3)
			{
				ans.pb(mp(r+1, cur+1));
				cur = mt[cur];
				ans.pb(mp(r+1, cur+1));
				r++;
			}
		}
	}
	cout << ans.size() << endl;
	for(pii p : ans) cout << p.f << " " << p.s << endl;
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
