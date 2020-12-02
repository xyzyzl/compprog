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

#define fileio(in, out)      \
	freopen(in, "r", stdin); \
	freopen(out, "w", stdout);

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

int n;
void solve()
{
	cin >> n; vi v(n);
	FOR(i, n) cin >> v[i];
	vi p = v;
	vi s = v;
	F1R(i, n-1) p[i] = max(p[i], p[i-1]);
	FORD(i, n-1) s[i] = max(s[i], s[i+1]);

	int mx = *max_element(v.begin(), v.end());
	vi ms;
	FOR(i, n) if(v[i] == mx) ms.pb(i);
	if(ms.size() >= 3)
	{
		cout << "YES" << endl;
		cout << ms[1] << " " << 1 << " " << n-ms[1]-1 << endl;
		return;
	} else
	{
		int lo = ms[0];
		int hi = lo+1;
		while(true)
		{
			if(lo == 0 || hi == n)
			{
				cout << "NO" << endl;
				return;
			}
			if(p[lo-1] == mx && s[hi] == mx)
			{
				cout << "YES" << endl;
				cout << lo << " " << hi-lo << " " << n-hi << endl;
				return;
			}
			int lf = (lo-1==0) ? INT_MIN : min(p[lo-2], v[lo-1]);
			int rg = (hi+1>=n) ? INT_MIN : min(s[hi+1], v[hi]);
			if(lf > rg)
			{
				mx = min(mx, v[lo-1]);
				--lo;
			} else
			{
				mx = min(mx, v[hi]);
				++hi;
			}
		}
	}	
}

signed main()
{
	DUEHOANG;
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
