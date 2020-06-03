// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 2005

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
vi pts;
ll adj_mat[MAXN][MAXN];

int par[MAXN];
ll wt[MAXN];
void prim()
{
	// just let the root be 0!!
	vi vis(n, 0);
	FOR(i, n) wt[i] = 5;
	wt[0] = 0;
	par[0] = -1;
	FOR(ct, n-1)
	{
		ll mn = 5;
		int ind = -1;
		FOR(i, n)
		{
			if(!vis[i] && wt[i] < mn)
			{
				mn = wt[i];
				ind = i;
			}
		}

		vis[ind] = 1;
		FOR(i, n)
		{
			if(!vis[i] && adj_mat[ind][i] < wt[i])
			{
				par[i] = ind;
				wt[i] = adj_mat[ind][i];
			}
		}
	}
	ll sum = 0;
	for(int i = 1; i < n; i++)
	{
		sum -= wt[i];
	}
	cout << sum << endl;
}

void read()
{
	cin >> n;
	FOR(i, n)
	{
		int x;
		cin >> x;
		pts.pb(x);
	}
	FOR(i, n)
	{
		FOR(j, n)
		{
			adj_mat[i][j]=-(pts[i]^pts[j]);
		}
	}
	
}

void solve()
{
	prim();
}

int main()
{
	fileio("superbull.in", "superbull.out");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		read();
		solve();
	}
	
}
