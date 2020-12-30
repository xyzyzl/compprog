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

void solve()
{
	int n, k; cin >> n >> k;
	vector<bool> bt(n); FOR(i, n)
	{
		char c; cin >> c;
		bt[i] = (c == '1');
	}
	int mn = min(k, 20); // k-mn are all zeroes.
	int n1 = 0;
	vector<bool> no((1 << mn));
	FOR(i, n-mn+1)
	{
		// try to start a seq at point i
		if(n1 >= k-mn)
		{
			// some masks are unworkable
			int bad = 0;
			FOR(j, mn)
			{
				bad += !bt[i+j];
				bad *= 2;
			}
			bad /= 2;
			no[bad] = 1;
		}
		if(bt[i]) n1++;
		else n1=0;
	}
	FOR(good, (1 << mn))
	{
		if(!no[good])
		{
			cout << "YES" << endl;
			FOR(i, k-mn) cout << 0;
			FORD(i, mn)
			{
				cout << (((good >> i) & 1) ? 1 : 0);
			}
			cout << endl;
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
