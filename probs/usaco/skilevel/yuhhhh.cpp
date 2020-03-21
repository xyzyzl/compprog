/*
number of times we needed an f in the chat
2
*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 505

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

int m,n,t,el[MAXN][MAXN];
vi start;

int z, p[MAXN * MAXN], sz[MAXN * MAXN], ans[MAXN * MAXN], ranq[MAXN*MAXN];
bool vis[MAXN * MAXN];

int find_set(int i)
{
	int j = p[i];
	if(p[j] != j) find_set(j);
	if(ans[i] == -1)
	{
		ans[i] = (ans[j] == -1 ? ans[p[j]] : ans[j]);
	}
	return p[i] = p[j];
}

bool union_set(int i, int j)
{
	int x = find_set(i);
	int y = find_set(j);
	if (x == y)
		return false;
	if(ranq[x] < ranq[y]) swap(x, y);
    p[y] = x; // bruh
    sz[x] += sz[y];
    if(ranq[x] == ranq[y]) ranq[x]++;
    return true;
}

void init()
{
	for(int i = 0; i < z; i++) p[i] = i;
	for(int i = 0; i < z; i++) sz[i] = 1;
	for(int i = 0; i < z; i++) ranq[i] = 0;
}

viii edges;

int compress(int r, int c)
{
	return r * n + c; // bogoya
}

void solve()
{
	cin >> m >> n >> t;
	z = m*n;
	fill(ans, ans + z + 5, -1);
	FOR(i, m) FOR(j, n)
	{
		cin >> el[i][j];
	}
	FOR(i, m) FOR(j, n)
	{
		bool bogoya;
		cin >> bogoya;
		if(bogoya) start.pb(compress(i, j));
	}
	init();
	// go through edge lengths and find the total dsu size
	// for each start point
	FOR(i, m) FOR(j, n-1)
	{
		int w = abs(el[i][j] - el[i][j+1]);
		edges.pb(mp(w, mp(compress(i, j), compress(i, j+1))));
	}
	FOR(i, m-1) FOR(j, n)
	{
		int w = abs(el[i][j] - el[i+1][j]);
		edges.pb(mp(w, mp(compress(i, j), compress(i+1, j))));
	}
	sort(edges.begin(), edges.end()); // sort by weight
	// then run the dsu thing
	int y = edges.size();
	FOR(x, y)
	{
		int a = find_set(edges[x].s.f), b = find_set(edges[x].s.s);
		if(a == b) continue;
		if(sz[a] + sz[b] >= t)
		{
			if(sz[a] < t) ans[a] = edges[x].f;
			if(sz[b] < t) ans[b] = edges[x].f;
		}
		union_set(a, b);
		// ++x; // YUH.*-1
	}
	ll sum = 0;
	for(int a : start)
	{
		// cerr << ans[a] << endl;
		find_set(a);
		sum += (ll) ans[a];
	}
	cout << sum << endl;
}

int main()
{
	DUEHOANG;
	fileio("skilevel.in", "skilevel.out");
	int useless = 1;
	// cin >> t; // uncomment if it's multitest
	while(useless--)
	{
		solve();
	}
	
}
