/**
ID: albert.28
LANG: C++14
PROB: poetry
**/

/// Time:

#include <bits/stdc++.h>

/**
Mod operations in O(lg n)
Source: Benjamin Qi, https://github.com/bqi343/USACO/blob/master/Implementations/11%20-20(4)/Operators/modOp.cpp?fbclid=IwAR0m2afS-1xVg9kgeF8q8EJIeP9TP3Lct8dYb_hPJuI5gqHP1Utp5EkiOQ8
**/

using namespace std;

#define MAXN 100005
#define MOD 1000000007

#define FOR(g,i,n) for(int i = g; i < n; i++)
#define FORD(g,i,n) for(int i = g; i >= n; i--)

#define apple() ios_base::sync_with_stdio(0)
#define hentai() cin.tie(); cout.tie()

#define mp make_pair
#define pb push_back
#define	ll long long
#define int ll
#define INF (1e15*1)+5
#define LL_INF (1e18*1)+5
#define bitinc(s) (s&-s)
#define endl '\n'

typedef pair<int, int> pii;
typedef pair<int, pii> iii;
typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mi;
#define f first
#define s second
typedef vector<pii> vii;
typedef vector<iii> viii;
typedef set<pii> sii;
typedef map<pii, pii> mii;

void fileio(char* in, char* out)
{
	freopen(in, "r", stdin);
	freopen(out, "w", stdout);
}

namespace modOp
{
    int ad(int a, int b, int mod = MOD) { return (a+b)%mod; }
    int sub(int a, int b, int mod = MOD) { return (a-b+mod)%mod; }
    int mul(int a, int b, int mod = MOD) { return (ll)a*b%mod; }

    int AD(int& a, int b, int mod = MOD) { return a = ad(a,b,mod); }
    int SUB(int& a, int b, int mod = MOD) { return a = sub(a,b,mod); }
    int MUL(int& a, int b, int mod = MOD) { return a = mul(a,b,mod); }

    int po (int b, int p, int mod = MOD) { return !p?1:mul(po(mul(b,b,mod),p/2,mod),p&1?b:1,mod); }
    int inv (int b, int mod = MOD) { return po(b,mod-2,mod); }

    int invGeneral(int a, int b) { // 0 < a < b, gcd(a,b) = 1
        if (a == 0) return b == 1 ? 0 : -1;
        int x = invGeneral(b%a,a);
        return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
    }
}

using namespace modOp;

int n, m;
bool can_reach_n[2505];
viii edges;
vi bck_lst[2505];
void dfs(int v)
{
	if(can_reach_n[v]) return;
	can_reach_n[v] = 1;
	for(int i : bck_lst[v])
	{
		dfs(i);
	}
}
int bf(int src)
{
	int dist[n];
	FOR(0, i, n) dist[i] = INF;
	dist[0] = 0;
	FOR(0, i, n-1) FOR(0, j, m)
	{
		int u = edges[j].s.f;
		int v = edges[j].s.s;
		int w = edges[j].f;
		if(dist[u] != INF && dist[u] + w < dist[v])
		{
			dist[v] = dist[u] + w;
		}
	}
	FOR(0, i, m)
	{
        int u = edges[i].s.f;
        int v = edges[i].s.s;
        int w = edges[i].f;
		if(can_reach_n[u] || can_reach_n[v]) if(dist[u] != INF && dist[u] + w < dist[v]) return -1;
	}
	return -dist[n-1];
}

int32_t main()
{
	apple();
	hentai();
	// fileio("thing.in", "thing.out");
	cin >> n >> m;
	FOR(0, i, m)
	{
		int a, b, w;
		cin >> a >> b >> w;
		edges.pb(mp(-w, mp(a-1, b-1)));
		bck_lst[b-1].pb(a-1);
	}
	dfs(n-1);
	cout << bf(0) << endl;
}
