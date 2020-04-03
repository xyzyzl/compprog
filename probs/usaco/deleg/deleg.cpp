// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 100005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
#define FOBIRD(i, n) for (int i = n; i >= 1; i--)
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

int n, from[MAXN];
vi adj[MAXN], thing[MAXN];

void dfs(int v, int p)
{
	from[v] = 1;
	for(int x : adj[v])
	{
		if(x == p) continue;
		dfs(x, v);
		from[v] += from[x];
		thing[v].pb(from[x]);
	}
	if(from[v] != n) thing[v].pb(n-from[v]);
}

int cur[MAXN];
bool test(int x)
{
	if((n-1)%x != 0) return 0;
	// cout << x << endl;
	memset(cur, 0, sizeof cur); // this needs to exist in order for
	// cur to remain 0 each time
	FOR(i, n)
	{
		int y = 0;
		// pairing things up
		for(int len : thing[i])
		{
			int z = len%x;
			if(!z) continue;
			if(cur[x-z])
			{
				cur[x-z]--;
				y--;
			} else
			{
				cur[z]++;
				y++;
			}
		}
		if(y) return 0; // pairing failed, there is some
		// number that cannot form a path of length k
	}
	return 1;
}

int main()
{
	fileio("deleg.in", "deleg.out");
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
		cin >> n;
		FOR(i, n-1)
		{
			int a, b;
			cin >> a >> b;
			--a; --b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		dfs(0, -1);
		FOBIR(i, n-1)
		{
			cout << test(i);
			// have some method to find if it's possible
		}
		cout << endl;
    }
    
}
