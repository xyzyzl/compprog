// Time:
// Algorithms:

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 55

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

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int n, m;
int arr[MAXN][MAXN];
bool vis[MAXN][MAXN];
void read()
{
	cin >> n >> m;
	FOR(i, n)
	{
		FOR(j, m)
		{
			vis[i][j] = 0;
			char c;
			cin >> c;
			if(c == '#') arr[i][j] = 0;
			else if(c == '.') arr[i][j] = 1;
			else if(c == 'G') arr[i][j] = 2;
			else arr[i][j] = 3;
		}
	}
}

void solve()
{
	// replace everything around bad with 0's
	FOR(i, n) FOR(j, m)
	{
		if(arr[i][j] != 3) continue;
		if(i)
		{
			// look at arr[i-1][j]
			if(arr[i-1][j] == 2)
			{
				cout << "No" << endl;
				return;
			}
			if(arr[i-1][j] != 3) arr[i-1][j] = 0;
		}
		if(j)
		{
			// look at arr[i-1][j]
			if(arr[i][j-1] == 2)
			{
				cout << "No" << endl;
				return;
			}
			if(arr[i][j-1] != 3) arr[i][j-1] = 0;
		}
		if(i < n-1)
		{
			// look at arr[i-1][j]
			if(arr[i+1][j] == 2)
			{
				cout << "No" << endl;
				return;
			}
			if(arr[i+1][j] != 3) arr[i+1][j] = 0;
		}
		if(j < m-1)
		{
			// look at arr[i-1][j]
			if(arr[i][j+1] == 2)
			{
				cout << "No" << endl;
				return;
			}
			if(arr[i][j+1] != 3) arr[i][j+1] = 0;
		}
	}

	queue<pii> q;
	q.push(mp(n-1, m-1));
	while(!q.empty())
	{
		pii p = q.front();
		q.pop();
		// cout << p.f << " " << p.s << endl;
		if((!arr[p.f][p.s]) || (vis[p.f][p.s])) continue;
		vis[p.f][p.s] = 1;
		FOR(i, 4)
		{
			pii np = mp(p.f + dx[i], p.s + dy[i]);
			if((!arr[np.f][np.s]) || (vis[np.f][np.s])) continue;
			if(np.f < 0 || np.f >= n || np.s < 0 || np.s >= m) continue;
			q.push(np);
		}
	}

	/*
	FOR(i, n)
	{
		FOR(j, m)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	FOR(i, n)
	{
		FOR(j, m)
		{
			cout << vis[i][j] << " ";
		}
		cout << endl;
	}
	*/

	FOR(i, n) FOR(j, m)
	{
		if((arr[i][j] == 2 && (!vis[i][j])) || (arr[i][j] == 3 && vis[i][j]))
		{
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
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
