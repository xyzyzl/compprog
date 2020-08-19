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

int n, m, k, path[MAXN], dist[MAXN];
vi adj[MAXN], bfs[MAXN];
int main()
{
	cin >> n >> m;
	FOR(i, m)
	{
		int a, b;
		cin >> a >> b;
		--a; --b;
		adj[a].pb(b);
		bfs[b].pb(a);
	}
	// find shortest path blah
	cin >> k;
	FOR(i, k)
	{
		cin >> path[i];
		--path[i];
	}
	memset(dist, -1, sizeof dist);
	qi q;
	q.push(path[k-1]); // this is the ending node
	dist[path[k-1]] = 0;
	while(!q.empty())
	{
		int tp = q.front();
		q.pop();
		for(int nx : bfs[tp])
		{
			if(dist[nx] == -1)
			{
				dist[nx] = dist[tp]+1;
				q.push(nx);
			}
		}
	}
	int mn = 0;
	int mx = 0;
	FOR(i, k-1)
	{
		if(dist[path[i+1]] > dist[path[i]] - 1) 
		{
			mn++;
			mx++;
			continue;
		}
		int thing = 0;
		for(int x : adj[path[i]]) if(x != path[i+1] && dist[x] == dist[path[i]]-1)
		{
			// cerr << path[i] << " " << x << " " << path[i+1] << endl;
			thing = 1;
			break;
		}
		mx += thing;
	}
	cout << mn << " " << mx << endl;
}
