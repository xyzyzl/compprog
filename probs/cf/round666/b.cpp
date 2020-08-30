// Time:
// Algorithms: 

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

ll po(ll x, int y)
{
	if(y == 0) return 1;
	else if(y%2 == 0)
		return po(x, y/2)*po(x,y/2);
	else
		return x*po(x,y/2)*po(x,y/2);
}

void solve()
{
	int n;
	cin >> n;
	vi v(n);
	FOR(i, n) cin >> v[i];
	sort(v.begin(), v.end());
	if(n > 64)
	{
		// 1 1 1 1 1 1 ... 1 is clearly best
		ll x = 0;
		FOR(i, n) x += v[i]-1ll;
		cout << x << endl;
	} else
	{
		long double x = pow(v[n-1], 1.0/(double)(n-1));
		ll ans = LLONG_MAX;
		vi u(2);
		u[0] = floor(x);
		u[1] = ceil (x);
		FOR(it, 2)
		{
			ll a = 0;
			FOR(i, n)
			{
				ll x = po(u[it], i);
				a += abs(v[i]-x);
			}
			ans = min(ans, a);
		}
		cout << ans << endl;
	}
}

int main()
{
	// freopen("b.txt", "r", stdin);
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
