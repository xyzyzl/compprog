// Time:
// Algorithms: 比较难

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 100005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
#define FOBIRD(i, n) for (int i = n; i >= 1; i--)
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

int n;
ll k, a[MAXN];

// number of cows s.t. marginal benefit >= x.
ll tot_c(double x)
{
	ll ret = 0LL;
	FOR(i, n)
	{
		ret += (ll)((sqrt(1 + 4.0 * a[i] / x) - 1)/(2.0));
	}
	return ret;
}

// check the # of cows working on each layer
void debug(double x)
{
	FOR(i, n)
	{
		cout << (ll)((sqrt(1 + 4.0 * a[i] / x) - 1)/(2.0)) << endl;
	}
}

void solve()
{
	cin >> n >> k;
	k-=n; // guaranteed to have one worker per floor
	FOR(i, n)
	{
		cin >> a[i];
	}
	// bin search on closest MB
	double lo = 0.0, hi = 1e18;
	// cout << hi << endl;
	FORD(f, 250)
	{
		double mid = (lo+hi)/2;
		if(tot_c(mid) >= k) lo = mid;
		else hi = mid;
	}
	// get actual answer
	double ans = 0;
	ll extra = 0;
	double x = lo;
	// debug(x);
	FOR(i, n)
	{
		ll y = (ll)((sqrt(1 + 4.0 * a[i] / x) - 1)/(2.0));
		ans += (double)(a[i])/(y+1.0);
		extra += y;
	}
	cout << (ll)round(ans - (k-extra)*x) << endl;
}

int main()
{
	fileio("tallbarn.in", "tallbarn.out");
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
