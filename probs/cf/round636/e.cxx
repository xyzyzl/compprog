// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

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

int n,m,a,b,c;
ll psum[MAXN];
vi adj[MAXN];
void read()
{
	cin >> n >> m >> a >> b >> c;
	memset(psum, 0, sizeof psum);
	vi shqip(m);
	FOR(i, m) cin >> shqip[i];
	sort(shqip.begin(), shqip.end());
	FOR(i, m)
	{
		if(!i) psum[i] = shqip[i];
		else psum[i] = psum[i-1] + shqip[i];
	}
	FOR(i, n+5) adj[i].clear();
	FOR(i, m)
	{
		int p, q;
		cin >> p >> q;
		--p; --q;
		adj[p].pb(q);
		adj[q].pb(p);
	}
}

vi find_dist(int v)
{
	/*
	FOR(i, n)
	{
		for(int j : adj[i]) cout << i << " " << j << ".." << endl;
	}
	*/
	vi ret(n), vis(n);
	qi q;
	q.push(v);
	// vis[v] = 1;
	fill(ret.begin(), ret.end(), INF);
	ret[v] = 0;
	while(!q.empty())
	{
		int tp = q.front();
		q.pop();
		if(vis[tp]) continue;
		vis[tp] = 1;
		for(int x : adj[tp])
		{
			// cout << x << endl;
			ret[x] = min(ret[x], ret[tp]+1);
			// vis[x] = 1;
			q.push(x);
		}
	}
	// FOR(i, n) cout << ret[i] << " ";
	// cout << endl;
	return ret;
}

void solve()
{
	// shqip
	// find distances from a, b, c
	--a; --b; --c; // first need to adjust the vertices
	vector<vi> vc;
	vc.pb(find_dist(a));
	vc.pb(find_dist(b));
	vc.pb(find_dist(c));

	// cout << vc[0][0] << " " << vc[1][0] << " " << vc[2][3] << endl;

	ll ans = 1e18;
	FOR(i, n)
	{
		// any can be the intermediate
		ll x = (ll)vc[0][i] + (ll)vc[1][i] + (ll)vc[2][i];
		if(x > (ll)m) continue; // llm orz!!
		ll y = (ll)vc[1][i];
		if(y > (ll)m) continue;

		ans = min(ans, psum[x-1] + psum[y-1]);
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
		read();
		solve();
	}
	
}
