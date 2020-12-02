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
#define ins insert
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
	int n; cin >> n; vi v(n+2);
	F1R(i, n) cin >> v[i];
	vi ps_0(n+2), ps_1(n+2), ss_0(n+2), ss_1(n+2);
	ps_0[1] = v[1];
	F1R(i, n+1) ps_0[i] = ps_0[i-1] + (i%2 ? 0 : v[i]);
	F1R(i, n+1) ps_1[i] = ps_1[i-1] + ((i+1)%2 ? 0 : v[i]);
	if(n%2) ss_0[n] = v[n];
	else ss_1[n] = v[n];
	FORD(i, n+1) ss_0[i] = ss_0[i+1] + (i%2 ? 0 : v[i]);
	FORD(i, n+1) ss_1[i] = ss_1[i+1] + ((i+1)%2 ? 0 : v[i]);
	int ans = 0;
	F1R(i, n)
	{
		if(ps_0[i-1] + ss_1[i+1] == ps_1[i-1] + ss_0[i+1])
		{
			ans++;
		}
	}
	cout << ans << endl;
}

signed main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
