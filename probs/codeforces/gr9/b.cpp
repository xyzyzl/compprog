// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 305

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

int n, m, a[MAXN][MAXN], b[MAXN][MAXN];
void read()
{
	memset(b, 0, sizeof b);
	cin >> n >> m;
	FOR(i, n) FOR(j, m) cin >> a[i][j];
}

void solve()
{
	FOR(i, n) FOR(j, m) if(a[i][j] > 4) 
	{
		cout << "NO" << endl;
		return;
	}
	if(a[0][0] > 2 || a[0][m-1] > 2 || a[n-1][0] > 2 || a[n-1][m-1] > 2)
	{
		cout << "NO" << endl;
		return;
	}
	F1R(i, m-2)
	{
		if(a[0][i] > 3)
		{
			cout << "NO" << endl;
			return;
		}
		if(a[n-1][i] > 3) 
		{
			cout << "NO" << endl;
			return;
		}
	}
	F1R(i, n-2)
	{
		if(a[i][0] > 3)
		{
			cout << "NO" << endl;
			return;
		}
		if(a[i][m-1] > 3)
		{
			cout << "NO" << endl;
			return;
		}
	}
	
	b[0][0] = b[0][m-1] = b[n-1][0] = b[n-1][m-1] = 2;
	F1R(i, m-2) b[0][i] = b[n-1][i] = 3;
	F1R(i, n-2) b[i][0] = b[i][m-1] = 3;
	F1R(i, n-2) F1R(j, m-2) b[i][j] = 4;
	cout << "YES" << endl;
	FOR(i, n)
	{
		FOR(j, m) cout << b[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	DUEHOANG;
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		read();
		solve();
	}
	
}
