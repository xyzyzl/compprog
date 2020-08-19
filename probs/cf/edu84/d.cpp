// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1000005

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

void solve()
{
	int n;
	cin >> n;
	vi c(n), p(n);
	FOR(i, n)
	{
		cin >> p[i];
		--p[i];
	}
	FOR(i, n) cin >> c[i];
	// put into a "cycle" format
	vi vis(n);
	int ans = INF;
	FOR(i, n)
	{
		if(vis[i]) continue;
		vi cycle;
		int v = i;
		while(!vis[v])
		{
			vis[v] = 1; // originally misplaced oops
			// cout << v << endl;
			cycle.pb(v);
			v=p[v];
			// vis[v] = 1;
		}
		F1R(j, cycle.size())
		{
			if(cycle.size() % j) continue;
			FOR(r, j)
			{
				bool good = 1;
				for(int k = r; k + j < cycle.size(); k += j)
					if(c[cycle[k]] != c[cycle[k+j]]) good = 0;
				// if(j == 1) cout << cycle.size() << endl;
				if(good)
				{
					MIN(ans, j);
					break;
				}
			}
		}
	}
	cout << ans << endl;
}

int main()
{
	DUEHOANG;
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
