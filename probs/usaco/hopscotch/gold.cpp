// Time:
// Algorithms:

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 755

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
#define int ll
#define MOD 1000000007
#define MOD2 998244353
#define INF (1e9 * 1) + 5

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

#define bitinc(x) x & -x

const int MAX(int &a, int b)
{
	return a = max(a, b);
}
const int MIN(int &a, int b)
{
	return a = min(a, b);
}

int r, c, k, gr[MAXN][MAXN];

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
struct BIT
{
	int n;
	vi bit, inds;
	BIT()
	{
	}
	BIT(vi compress)
	{
		inds.pb(-1);
		for (int x : compress)
			inds.pb(x);
		inds.pb(MOD + 1);
		n = inds.size();
		bit = vi(n, 0);
	}
	int sum(int i)
	{
		int ind = prev(upper_bound(inds.begin(), inds.end(), i)) - inds.begin();
		int sm = 0;
		while (ind > 0)
		{
			AD(sm, bit[ind]);
			ind -= bitinc(ind);
		}
		return sm;
	}
	void upd(int i, int val)
	{
		int ind = prev(upper_bound(inds.begin(), inds.end(), i)) - inds.begin();
		while (ind < n)
		{
			AD(bit[ind], val);
			ind += bitinc(ind);
		}
	}
};
BIT bits[600000];
BIT tot;
vi exist[600000];

void solve()
{
	fileio("hopscotch.in", "hopscotch.out");
	cin >> r >> c >> k;
	FOR(i, r)
	FOR(j, c)
	{
		cin >> gr[i][j];
	}
	FOR(j, c)
	FOR(i, r)
	{
		if (!exist[gr[i][j]].empty() && exist[gr[i][j]].back() == j)
			continue;
		exist[gr[i][j]].pb(j);
	}
	F1R(i, k)
	{
		if (exist[i].size())
			bits[i] = BIT(exist[i]);
	}
	vi tmp;
	FOR(i, c)
	{
		tmp.pb(i);
	}
	tot = BIT(tmp);
	tot.upd(0, 1);
	bits[gr[0][0]].upd(0, 1);
	FOR(i, r - 1)
	{
		if (i == 0)
			continue;
		FORD(j, c - 1)
		{
			if (j == 0)
				continue;
			int val = sub(tot.sum(j - 1), bits[gr[i][j]].sum(j - 1));
			tot.upd(j, val);
			bits[gr[i][j]].upd(j, val);
		}
	}
	cout << sub(tot.sum(c - 2), bits[gr[r - 1][c - 1]].sum(c - 2)) << endl;
}

signed main()
{
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while (t--)
	{
		solve();
	}
}
