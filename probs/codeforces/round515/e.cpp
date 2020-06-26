// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1000005

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
map<int, vii> layers;
pii l[MAXN];

ll dp[MAXN][2];

ll dist(pii a, pii b)
{
	return abs(a.f - b.f) + abs(a.s - b.s);
}

bool cmp(pii a, pii b)
{
	if(a.f == b.f) return a.s > b.s;
	return a.f < b.f;
}

void read()
{
	cin >> n;
	FOR(i, n)
	{
		cin >> l[i].f >> l[i].s;
		int sm = max(l[i].f, l[i].s);
		layers[sm].pb(l[i]);
	}
	layers[0].pb(mp(0,0));
	// cerr << layers.size() << endl;
}

void solve()
{
	for(auto &x : layers)
	{
		// cout << x.f << endl;
		sort(x.s.begin(), x.s.end(), cmp); // in increasing x-order AND decreasing y-order
		// now x.s[0] is the left array thing, and x.s.back() is the right array thing.
	}
	FOR(i, layers.size() + 1)
	{
		dp[i][0] = dp[i][1] = (1ll << 60);
	}
	dp[0][0] = dp[0][1] = 0;
	int lv = 0;
	int pre = 0;
	for(auto &x : layers) // ogres are like onions -- they have layers
	{
		lv++;
		// cerr << lv << " " << pre << endl;
		// cerr << x.s.size() << endl;
		// cout << pre << ", " << lv << endl;
		pii p_l = layers[pre][0];
		pii p_r = layers[pre].back();
		// dp[lv][0] = min(dp[lv][0], dist(x.s[0], x.s.back()) + min(dist(x.s.back(), p_l) + dp[lv-1][0], dist(x.s.back(), p_r) + dp[lv-1][1]));
		dp[lv][0] = min(dp[lv][0], dist(x.s[0], x.s.back()) + dist(x.s.back(), p_l) + dp[lv-1][0]);
		dp[lv][0] = min(dp[lv][0], dist(x.s[0], x.s.back()) + dist(x.s.back(), p_r) + dp[lv-1][1]);
		// dp[lv][1] = min(dp[lv][1], dist(x.s[0], x.s.back()) + min(dist(x.s[0], p_l) + dp[lv-1][0], dist(x.s[0], p_r) + dp[lv-1][1]));
		dp[lv][1] = min(dp[lv][1], dist(x.s[0], x.s.back()) + dist(x.s[0], p_l) + dp[lv-1][0]);
		dp[lv][1] = min(dp[lv][1], dist(x.s[0], x.s.back()) + dist(x.s[0], p_r) + dp[lv-1][1]);
		pre = x.f;
	}
	cout << min(dp[lv][0], dp[lv][1]) << endl;
}

int main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		read();
		solve();
	}
	
}
