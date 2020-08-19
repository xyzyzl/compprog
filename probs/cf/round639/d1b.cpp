// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1505

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

int n, m;
bool col[MAXN][MAXN];
void read()
{
	cin >> n >> m;
	FOR(i, n) FOR(j, m)
	{
		char c;
		cin >> c;
		if(c == '#') col[i][j] = 1;
		else col[i][j] = 0;
	}
}

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int grp[MAXN][MAXN];
void floodfill(int i, int j, int color)
{
	grp[i][j] = color;
	for(int k = 0; k < 4; k++)
	{
		if(grp[i + dx[k]][j + dy[k]]) continue;
		if(col[i + dx[k]][j + dy[k]])
			floodfill(i + dx[k], j + dy[k], color);
	} // hussar hussar
}

void solve()
{
	// it's easy to see that the North magnet can move in any
	// part of the connected component. However, when doesn't the
	// solution exist?
	//
	// Way 1: Discontinuous Black Segment
	// Way 2: All-white row w/o matching column to throwaway
	// so this boils down to floodfill
	
	/** check for bad thing
	 * also check for all-white row/col
	 **/
	short wrow = 0; // white row
	FOR(i, n)
	{
		int cur = 0;
		int pre = 0;
		bool blk = 0;
		bool off = 0;
		FOR(j, m)
		{
			cur += col[i][j];
			if(cur != pre)
			{
				if(blk && off)
				{
					// cerr << i << " " << j << endl;
					// multiple black segments
					cout << -1 << endl;
					return;
				} else blk = 1;
			} else if(blk)
			{
				off = 1;
			}
			pre = cur;
		}
		if(!blk) wrow = 1;
	}
	// cerr << "homosexuality" << endl;
	short wcol = 0;
	FOR(j, m)
	{
		int cur = 0;
		int pre = 0;
		bool blk = 0;
		bool off = 0;
		FOR(i, n)
		{
			cur += col[i][j];
			if(cur != pre)
			{
				if(blk && off)
				{
					// multiple black segments
					cout << -1 << endl;
					return;
				} else blk = 1;
			} else if(blk)
			{
				off = 1;
			}
			pre = cur;
		}
		if(!blk) wcol = 1;
	}
	if(wrow + wcol == 1)
	{
		// cerr << "GEAEY" << endl;
		cout << -1 << endl;
		return;
	}
	/** ok now can floodfill **/
	int ans = 0;
	FOR(i, n) FOR(j, m)
	{
		if(!grp[i][j] && col[i][j]) floodfill(i, j, ++ans);
	}
	cout << ans << endl;
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
