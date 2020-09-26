/**
ID: albert.28
LANG: C++14
PROB: poetry
**/

#include <bits/stdc++.h>

/**
Mod operations in O(lg n)
Source: Benjamin Qi, https://github.com/bqi343/USACO/blob/master/Implementations/11%20-20(4)/Operators/modOp.cpp?fbclid=IwAR0m2afS-1xVg9kgeF8q8EJIeP9TP3Lct8dYb_hPJuI5gqHP1Utp5EkiOQ8
**/

using namespace std;

#define MAXN 100005
#define MOD 1000000007

#define FOR(g, i, n) for (int i = g; i < n; i++)
#define FORD(g, i, n) for (int i = g; i >= n; i--)

#define apple() ios_base::sync_with_stdio(0)
#define hentai() \
	cin.tie();   \
	cout.tie()

#define mp make_pair
#define pb push_back
#define ll long long
#define int ll
#define INF (1e9 * 1) + 5
#define LL_INF (1e18 * 1) + 5
#define bitinc(s) (s & -s)
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

void fileio(char *in, char *out)
{
	freopen(in, "r", stdin);
	freopen(out, "w", stdout);
}

namespace modOp
{
	int ad(int a, int b, int mod = MOD) { return (a + b) % mod; }
	int sub(int a, int b, int mod = MOD) { return (a - b + mod) % mod; }
	int mul(int a, int b, int mod = MOD) { return (ll)a * b % mod; }

	int AD(int &a, int b, int mod = MOD) { return a = ad(a, b, mod); }
	int SUB(int &a, int b, int mod = MOD) { return a = sub(a, b, mod); }
	int MUL(int &a, int b, int mod = MOD) { return a = mul(a, b, mod); }

	int po(int b, int p, int mod = MOD) { return !p ? 1 : mul(po(mul(b, b, mod), p / 2, mod), p & 1 ? b : 1, mod); }
	int inv(int b, int mod = MOD) { return po(b, mod - 2, mod); }

	int invGeneral(int a, int b)
	{ // 0 < a < b, gcd(a,b) = 1
		if (a == 0)
			return b == 1 ? 0 : -1;
		int x = invGeneral(b % a, a);
		return x == -1 ? -1 : ((1 - (ll)b * x) / a + b) % b;
	}
} // namespace modOp

using namespace modOp;
long long M, N, L, H, B;
long long ct;
// ndivs[i] is the number of prime divisors of i
int ndivs[100001];
// divs[i][j] is the list of i prime divisors of j
int divs[32];

void solve()
{
	int n = 1e9;
	cin >> n;
	vi v;
	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			if (n / i == i)
				v.pb(i);

			else
			{
				if (i != 1)
					v.pb(i);
				v.pb(n / i);
			}
		}
	}
	sort(v.begin(), v.end());
	vi p;
	int m = n;
	if(n % 2 == 0) p.pb(2);
	while (n % 2 == 0)
	{
		n = n / 2;
	}

	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		if(n % i == 0) p.pb(i);
		while (n % i == 0)
		{
			n = n / i;
		}
	}

	if (n > 2)
		p.pb(n);
	n = m;
	if (v.size() == 3 && p.size() == 2)
	{
		cout << v[0] << " " << v[1] << " " << v[2] << endl;
		cout << 1 << endl;
	}
	else
	{
		vi adj;
		unordered_map<int, bool> vis;
		FOR(0, i, p.size())
		{
			int p1 = p[i], p2 = p[(i+1)%p.size()];
			for(int k : v)
			{
				if(!vis[k] && k%p1==0 && k%p2==0)
				{
					adj.pb(k);
					vis[k] = 1;
					break;
				}
			}
		}
		FOR(0, i, p.size())
		{
			int p1 = p[i];
			vis[p1] = 1;
			cout << p1 << ' ';
			for(int k : v)
			{
				if(!vis[k] && k%p1==0)
				{
					vis[k] = 1;
					cout << k << ' ';
				}
			}
			if(p.size() > 1) cout << adj[i] << ' ';
		}
		cout << endl;
		cout << 0 << endl;
	}
}

signed main()
{
	int t;
	cin >> t;
	while (t--)
		solve();
}
