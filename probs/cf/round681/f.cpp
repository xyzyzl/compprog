#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
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
// ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;
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

void solve()
{
	int n,k; cin >> n >> k;
	vi a(n), b(k), nxt(n+5), pre(n+5);
	FOR(i, n) cin >> a[i];
	FOR(i, n)
	{
		nxt[a[i]] = i;
	}
	FOR(i, k) cin >> b[i];
	set<pii> arem;
	si brem;
	FOR(i, n) arem.insert(mp(i, a[i]));
	FOR(i, k) brem.insert(b[i]);
	ll wys = 1;
	FOR(i, k)
	{
		int nx = b[i];
		auto nt = arem.upper_bound(mp(nxt[nx], nx));
		arem.erase(arem.find(mp(nxt[nx], nx)));
		int ab,be;
		if(nt == arem.end()) ab = -1;
		else ab = nt->s;
		if(nt == arem.begin()) be = -1;
		else be = prev(nt)->s;
		// cerr << ab << ' ' << be << endl;
		if((brem.count(ab) || ab == -1) && (brem.count(be) || be == -1)) 
		{
			wys = 0;
		} else if(brem.count(ab) || brem.count(be)) 
		{
			// nothing happens
		} else if(ab != -1 && be != -1) 
		{
			wys *= 2;
			wys %= MOD2;
		}
	}
	cout << wys << endl;
}

signed main()
{
	DUEHOANG;
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
