// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1000005

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

int n, m, c, indeg[MAXN], arr[MAXN];
vii adj[MAXN];
int main()
{
	fileio("timeline.in", "timeline.out");
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
		cin >> n >> m >> c;
		FOR(i, n) cin >> arr[i];
		FOR(i, c) 
		{
			int a, b, w;
			cin >> a >> b >> w;
			--a; --b;
			adj[a].pb({b,w});
			++indeg[b];
		}
		qi q;
		FOR(i, n) if(!indeg[i]) q.push(i);
		while(!q.empty())
		{
			int tp = q.front();
			q.pop();
			for(pii p : adj[tp])
			{
				arr[p.f] = max(arr[p.f], arr[tp] + p.s);
				if(!(--indeg[p.f])) q.push(p.f); // only push once after
				// all dependencies are resolved.
			}
		}
		FOR(i, n) cout << arr[i] << endl;
    }
    
}
