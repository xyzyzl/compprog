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
	int n;
	cin >> n;
	char c[n][n];
	FOR(i, n) FOR(j, n)
	{
		cin >> c[i][j];
	}
	vii ans;
	int m1=0,m2=0;
	if(c[0][1] == c[1][0])
	{
		m1 = 1;
	}
	if(c[n-2][n-1] == c[n-1][n-2])
	{
		m2 = 1;
	}
	if(m1 && m2)
	{
		if(c[0][1] == c[n-1][n-2])
		{
			cout << 2 << endl;
			cout << 1 << " " << 2 << endl;
			cout << 2 << " " << 1 << endl;
			return;
		} else
		{
			cout << 0 << endl;
			return;
		}
	} else if(!m1 && !m2)
	{
		cout << 2 << endl;
		if(c[0][1] != c[n-1][n-2])
		{
			// invert these
			cout << 1 << " " << 2 << endl;
			cout << n << " " << (n-1) << endl;
		} else 
		{
			// invert (1,2) and (n-1,n)
			cout << 1 << " " << 2 << endl;
			cout << (n-1) << " " << n << endl;
		}
	} else 
	{
		cout << 1 << endl;
		if(m1)
		{
			// m1 matches, m2 does not
			if(c[n-1][n-2] == c[0][1]) cout << n << " " << (n-1) << endl;
			if(c[n-2][n-1] == c[0][1]) cout << (n-1) << " " << n << endl;
		} else 
		{
			if(c[n-1][n-2] == c[0][1]) cout << 1 << " " << 2 << endl;
			if(c[n-1][n-2] == c[1][0]) cout << 2 << " " << 1 << endl;
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
