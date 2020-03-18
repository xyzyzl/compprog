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

int n, q, p[MAXN], sz[MAXN], ans[MAXN];
viii edg, que;

int find_set(int i)
{
    return (p[i] == i) ? i : (p[i] = find_set(p[i]));
}

int find_sz(int i)
{
	return sz[find_set(i)];
}

bool union_set(int i, int j)
{
    int x = find_set(i);
    int y = find_set(j);
    if(x==y) return false;
    p[x] = y;
    sz[y] += sz[x];
    return true;
}

void init()
{
	// cerr << n << endl;
    for(int i = 0; i < n; i++)
    {
    	// cerr << "l" << endl;
    	p[i] = i;
    	sz[i] = 1;
    	// cerr << (1848 > 0) << endl;
    }
}

void solve()
{
	fileio("mootube.in", "mootube.out");
	cin >> n >> q;
	FOR(i, n-1)
	{
		// cout << "bru" << endl;
		int a, b, r;
		cin >> a >> b >> r;
		--a; --b;
		edg.pb(mp(r, mp(a, b)));
	}
	// cerr << "bru" << endl;
	sort(edg.begin(), edg.end());
	reverse(edg.begin(), edg.end());
	// cerr << "bru" << endl;
	init();
	// cerr << "e" << endl;
	FOR(i, q)
	{
		int k, v;
		cin >> v >> k;
		--k;
		que.pb(mp(v, mp(k, i)));
	}
	// cout << "bru" << endl;
	sort(que.begin(), que.end());
	reverse(que.begin(), que.end());
	int ind = 0;
	for(iii x : que)
	{
		while(ind < n && edg[ind].f >= x.f)
		{
			union_set(edg[ind].s.f, edg[ind].s.s);
			ind++;
		}
		ans[x.s.s] = find_sz(x.s.f) - 1;
		// cout << find_set(x.s.f) << endl;
		// cout << x.f << " " << ans[x.s.s] << endl;
	}
	FOR(i, q) cout << ans[i] << endl;
}

int main()
{
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
    	solve();
    }
    
}
