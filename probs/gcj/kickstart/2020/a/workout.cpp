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

int n, k, m[MAXN], d[MAXN];

bool ok(int x)
{
	int r_tot = 0;
	FOR(i, n-1)
	{
		r_tot += ceil(-1.0 + (double)d[i]/(double)x);
	}
	return r_tot <= k;
}

void solve(int x)
{
	memset(m, 0, sizeof m);
	memset(d, 0, sizeof d);
	cin >> n >> k;
	FOR(i, n)
	{
		cin >> m[i];
	}
	FOR(i, n-1)
	{
		d[i] = m[i+1]-m[i];
	}
	int lo = 1;
	int hi = INF;
	while(lo < hi)
	{
		int mid = (lo+hi)/2;
		if(ok(mid))
		{
			hi = mid; // mid is attainable
		} else lo = mid+1; // mid not attainable
	}
	cout << "Case #" << x << ": " << lo << endl;
}

int main()
{
	int t = 1;
	cin >> t; // uncomment if it's multitest
	int x = 0;
	while(t--)
	{
		++x;
		solve(x);
	}
}
