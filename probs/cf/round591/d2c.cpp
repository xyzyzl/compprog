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

int n;
ll p[MAXN], x, a, y, b, k;
bool ok(int l)
{
	int _xy=0, _x=0, _y=0;
	FOR(i, l)
	{
		if((i+1)%a == 0 && (i+1)%b == 0) _xy++;
		else if((i+1)%a == 0) _x++;
		else if((i+1)%b == 0) _y++;
	}
	// cerr << _xy << " " << _x << " " << _y << endl;
	int id = 0;
	ll ans = 0;
	FOR(i, _xy) ans += (x+y)*p[id++];
	FOR(i,  _x) ans += x    *p[id++];
	FOR(i,  _y) ans += y    *p[id++];
	// cerr << ans << endl;
	return ans >= k;
}

void solve()
{
	cin >> n;
	FOR(i, n)
	{
		cin >> p[i];
		p[i] /= 100;
	}
	sort(p, p+n);
	reverse(p, p+n);
	cin >> x >> a >> y >> b >> k;
	if(x < y) 
	{
		swap(x,y);
		swap(a,b);
	}
	int lo = 0, hi = n+1;
	while(lo+1 < hi)
	{
		int mid = (lo+hi)/2;
		if(ok(mid)) hi = mid;
		else lo = mid;
	}
	if(hi > n) cout << -1 << endl;
	else cout << hi << endl;
}

int main()
{
	DUEHOANG;
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}