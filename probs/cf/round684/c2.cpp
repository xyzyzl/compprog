#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 105

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

struct thg
{
	pii a,b,c;
	thg(int a1, int a2, int b1, int b2, int c1, int c2)
	{
		this->a = mp(a1,a2);
		this->b = mp(b1,b2);
		this->c = mp(c1,c2);
	}
};

void solve()
{
	int n,m; cin >> n >> m;
	int c[MAXN][MAXN];
	vector<thg> v;
	F1R(i, n) F1R(j, m)
	{
		char thing; cin >> thing;
		c[i][j] = thing-'0';
	}
	F1R(i, n-2)
	{
		F1R(j, m)
		{
			if(c[i][j])
			{
				if(j != m) 
				{
					v.pb(thg(i,j,i+1,j,i+1,j+1));
					c[i][j] = !c[i][j];
					c[i+1][j] = !c[i+1][j];
					c[i+1][j+1] = !c[i+1][j+1];
				} else 
				{
					v.pb(thg(i,j,i+1,j,i+1,j-1));
					c[i][j] = !c[i][j];
					c[i+1][j] = !c[i+1][j];
					c[i+1][j-1] = !c[i+1][j-1];
				}
			}
		}
	}
	F1R(j, m-2)
	{
		if(c[n-1][j])
		{
			v.pb(thg(n-1, j, n-1, j+1, n, j+1));
			c[n-1][j] = !c[n-1][j];
			c[n-1][j+1] = !c[n-1][j+1];
			c[n][j+1] = !c[n][j+1];
		}
		if(c[n][j])
		{
			v.pb(thg(n, j, n-1, j+1, n, j+1));
			c[n][j] = !c[n][j];
			c[n-1][j+1] = !c[n-1][j+1];
			c[n][j+1] = !c[n][j+1];
		}
	}
	int msk = (1 << 3) * c[n][m] + (1 << 2) * c[n][m-1] + (1 << 1) * c[n-1][m] + c[n-1][m-1];
	vector<vector<thg> > A(16);
	// 0: empty
	// 7: n-1 m-1 n m-1 n-1 m
	A[7].pb(thg(n-1,m-1,n,m-1,n-1,m));
	// 11: n-1 m-1 n-1 m n m
	A[11].pb(thg(n-1,m-1,n-1,m,n,m));
	// 13: n-1 m-1 n m-1 n m
	A[13].pb(thg(n-1,m-1,n,m-1,n,m));
	// 14: n m-1 n-1 m n m
	A[14].pb(thg(n,m-1,n-1,m,n,m));
	// 9: n-1 m-1 n m-1 n-1 m + 14
	A[9].pb(thg(n-1, m-1, n, m-1, n-1, m));
	for(auto x : A[14]) A[9].pb(x);
	// 6: n-1 m-1 n m-1 n m + 13
	A[6].pb(thg(n-1, m-1, n, m-1, n, m));
	for(auto x : A[11]) A[6].pb(x);
	// 1: n-1 m-1 n m-1 n-1 m, the contents of 6
	A[1].pb(thg(n-1, m-1, n, m-1, n-1, m));
	for(auto x : A[6]) A[1].pb(x);
	// 2: n-1 m-1 n-1 m n m + 9
	A[2].pb(thg(n-1, m-1, n-1, m, n, m));
	for(auto x : A[9]) A[2].pb(x);
	// 4: n-1 m-1 n m-1 n m + 9
	A[4].pb(thg(n-1, m-1, n, m-1, n, m));
	for(auto x : A[9]) A[4].pb(x);
	// 8: n-1 m n m-1 n m + 6
	A[8].pb(thg(n-1, m, n, m-1, n, m));
	for(auto x : A[6]) A[8].pb(x);
	// 15: n-1 m-1 n m-1 n-1 m + 8
	A[15].pb(thg(n-1, m-1, n, m-1, n-1, m));
	for(auto x : A[8]) A[15].pb(x);
	// 3: n-1 m-1 n m-1 n-1 m + 4
	A[3].pb(thg(n-1, m-1, n, m-1, n-1, m));
	for(auto x : A[4]) A[3].pb(x);
	// 5: n-1 m-1 n m-1 n-1 m + 2
	A[5].pb(thg(n-1, m-1, n, m-1, n-1, m));
	for(auto x : A[2]) A[5].pb(x);
	// 10: n-1 m n m-1 n m + 4
	A[10].pb(thg(n-1, m, n, m-1, n, m));
	for(auto x : A[4]) A[10].pb(x);
	// 12: n-1 m n m-1 n m + 2
	A[12].pb(thg(n-1, m, n, m-1, n, m));
	for(auto x : A[2]) A[12].pb(x);
	for(auto x : A[msk]) v.pb(x);

	cout << v.size() << endl;
	for(thg x : v)
	{
		cout << x.a.f << ' ' << x.a.s << ' ' << x.b.f << ' ' << x.b.s << ' ' << x.c.f << ' ' << x.c.s << endl;
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
