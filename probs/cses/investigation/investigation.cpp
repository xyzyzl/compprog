/// Time: O(m lg n)

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
#define INF (1e9*1)+5
#define LL_INF (1e18*1)+5
#define bitinc(s) (s&-s)
#define endl '\n'

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mi;
#define f first
#define s second
typedef vector<pii> vii;
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

int n, m, wt[MAXN], num[MAXN], mn[MAXN], mx[MAXN], vis[MAXN];
vii adj[MAXN];

/// Set-based Dijkstra implementation.
void dijk(int src)
{
	fill(wt, wt + n, LL_INF);
	fill(num, num+n, 0);
	fill(mn, mn+n, 0);
	fill(mx, mx+n, 0);

	set<pii> pq;
	pq.insert(mp(0, src));

	wt[src] = 0;
	num[src] = 1;

	int ct = 0;
	while (!pq.empty())
	{
		pii tp = *pq.begin();
		pq.erase(pq.begin());
		if(!vis[tp.s])
		{
			vis[tp.s] = 1;
			for (pii gu : adj[tp.s])
			{
				int w = gu.f;
				int ind = gu.s;
				if (wt[tp.s] + w < wt[ind])
				{
					// pq.erase(mp(wt[ind], ind)); /// you can't efficiently erase with a priority queue
					wt[ind] = wt[tp.s] + w;
					num[ind] = num[tp.s];
					mn[ind] = mn[tp.s]+1;
					mx[ind] = mx[tp.s]+1;
					pq.insert(mp(wt[ind], ind));
				} else if(wt[tp.s] + w == wt[ind])
				{
					num[ind] = (num[ind] + num[tp.s]) % MOD;
					mn[ind] = min(mn[ind], mn[tp.s]+1);
					mx[ind] = max(mx[ind], mx[tp.s]+1);
				}
			}
		}
	}
}

main()
{
	cin >> n >> m;
	FOR(0, i, m)
	{
		int a, b, w;
		cin >> a >> b >> w;
		a--; b--;
		adj[a].pb(mp(w, b));
	}
	dijk(0);
	cout << wt[n-1] << " " << num[n-1] << " " << mn[n-1] << " " << mx[n-1] << endl;
}
