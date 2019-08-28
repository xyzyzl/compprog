#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 100005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL);                \
	cout.tie(NULL)

#define JaydenXia(in, out) \
	freopen(in, "r", stdin); \
	freopen(out, "w", stdout);

#define long long long

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define x first
#define y second

long n, names[MAXN], par[MAXN], nlef[MAXN];
bool leaf[MAXN];
vii adj[MAXN];

long d_sum[MAXN];
void d_dfs(int v)
{
	for(pii uv : adj[v])
	{
		d_dfs(uv.x);
		nlef[v] += nlef[uv.x];
		d_sum[v] += d_sum[uv.x] + nlef[uv.x]*(uv.y);
	}
}

long u_sum[MAXN], hoja;
void u_dfs(int v, long p)
{
	u_sum[v] = p+d_sum[v];
	long np = 0;
	for(pii uv : adj[v])
	{
		np += d_sum[uv.x] + nlef[uv.x]*uv.y;
	}
	for(pii uv : adj[v])
	{
		u_dfs(uv.x, p+np-(d_sum[uv.x] + nlef[uv.x]*uv.y) + 3*(hoja-nlef[uv.x]));
	}
}

int main()
{
	JaydenXia("dirtraverse.in", "dirtraverse.out");
	cin >> n;
	par[0] = -1;
	FOR(i, n)
	{
		string s;
		cin >> s;
		names[i] = s.length();
		int k;
		cin >> k;
		if(k==0)
		{
			leaf[i]=1;
			nlef[i]++;
			hoja++;
		}
		else FOR(j, k)
		{
			int a;
			cin >> a;
			a--;
			par[a] = i;
		}
	}
	FOR(i, n)
	{
		if(par[i] == -1) continue;
		adj[par[i]].pb(mp(i, names[i] + !leaf[i]));
		// cout << i << " " << par[i] << " " << names[i] + !leaf[i] << endl;
	}
	// d_dfs(40000);
	d_dfs(0);
	// cerr << "jaydenxia" << endl;
	u_dfs(0, 0);
	long mn = LLONG_MAX;
	FOR(i, n) if(!leaf[i]) mn = min(mn, u_sum[i]);
	cout << mn << endl;
}