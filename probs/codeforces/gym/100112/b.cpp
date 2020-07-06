// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 100005

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

int n, ord[2][MAXN];
void read()
{
	cin >> n;
	FOR(v, 2) FOR(i, n) cin >> ord[v][i];
}

ll bit[2][MAXN];

ll sum(int v, int ind)
{
	ll sm = 0;
	while(ind > 0)
	{
		sm += bit[v][ind];
		ind -= bitinc(ind);
	}
	return sm;
}
void upd(int v, int ind, ll val)
{
	while(ind <= n)
	{
		bit[v][ind] += val;
		ind += bitinc(ind);
	}
}

// the number of inversions in r
ll num_inv(int v)
{
	// cerr << "hi" << endl;
	ll ct = 0;
	int mx = 0;
	FOR(i, n)
	{
		bit[v][i] = 0;
	}
	FORD(i, n)
	{
		// cerr << ct << endl;
		ct += sum(v, ord[v][i]-1);
		// cerr << "G" << endl;
		upd(v, ord[v][i], 1);
		// cerr << "h" << endl;
	}
	return ct;
}

void solve()
{
	int x = num_inv(0), y = num_inv(1);
	cerr << x << " " << y << endl;
	if(x % 2 == y % 2) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
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
