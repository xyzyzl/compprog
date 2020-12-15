#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace std;

#define MAXN 105

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
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
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

int n, m;
int R[MAXN][MAXN], S[MAXN][MAXN], R2[MAXN][MAXN], S2[MAXN][MAXN];
int psR[MAXN][MAXN], psS[MAXN][MAXN], vis[MAXN][MAXN];

bool ck(int B)
{
	memset(vis, 0, sizeof vis);
	FOR(i, m) FOR(j, n)
	{
		R2[i][j] = R[i][j];
		S2[i][j] = S[i][j];
	}
	while(true)
	{
		bool found = 0;
		FORD(i, m-B+1) FORD(j, n-B+1)
		{
			if(vis[i][j]) continue;
			int rx = psR[i+B-1][j+B-1];
			if(i) rx -= psR[i-1][j+B-1];
			if(j) rx -= psR[i+B-1][j-1];
			if(i && j) rx += psR[i-1][j-1];
			int sx = psS[i+B-1][j+B-1];
			if(i) sx -= psS[i-1][j+B-1];
			if(j) sx -= psS[i+B-1][j-1];
			if(i && j) sx += psS[i-1][j-1];
			if(rx == B*B || sx == B*B)
			{
				vis[i][j] = 1;
				found = 1;
				FOR(i1, B) FOR(j1, B)
				{
					R[i+i1][j+j1] = 1;
					S[i+i1][j+j1] = 1;
				}
				psR[0][0] = R[0][0];
				psS[0][0] = S[0][0];
				FOR(i, m) FOR(j, n)
				{
					psR[i][j] = R[i][j];
					psS[i][j] = S[i][j];
					if(i)
					{
						psR[i][j] += psR[i-1][j];
						psS[i][j] += psS[i-1][j];
					}
					if(j)
					{
						psR[i][j] += psR[i][j-1];
						psS[i][j] += psS[i][j-1];
					}
					if(i && j)
					{
						psR[i][j] -= psR[i-1][j-1];
						psS[i][j] -= psS[i-1][j-1];
					}
				}
				goto here;
			}
		}
here:
		if(!found) break;
	}
	int rx = 0, sx = 0;
	FOR(i, m) FOR(j, n)
	{
		rx += R[i][j];
		sx += S[i][j];
	}
	FOR(i, m) FOR(j, n)
	{
		R[i][j] = R2[i][j];
		S[i][j] = S2[i][j];
	}
	psR[0][0] = R[0][0];
	psS[0][0] = S[0][0];
	FOR(i, m) FOR(j, n)
	{
		psR[i][j] = R[i][j];
		psS[i][j] = S[i][j];
		if(i)
		{
			psR[i][j] += psR[i-1][j];
			psS[i][j] += psS[i-1][j];
		}
		if(j)
		{
			psR[i][j] += psR[i][j-1];
			psS[i][j] += psS[i][j-1];
		}
		if(i && j)
		{
			psR[i][j] -= psR[i-1][j-1];
			psS[i][j] -= psS[i-1][j-1];
		}
	}
	if(rx == m*n && sx == m*n)
	{
		return 1;
	}
	return 0;
}

void solve()
{
	cin >> m >> n;
	FOR(i, m) FOR(j, n)
	{
		char c; cin >> c;
		R[i][j] = c == 'R';
		S[i][j] = c == 'S'; 
	}
	psR[0][0] = R[0][0];
	psS[0][0] = S[0][0];
	FOR(i, m) FOR(j, n)
	{
		psR[i][j] = R[i][j];
		psS[i][j] = S[i][j];
		if(i)
		{
			psR[i][j] += psR[i-1][j];
			psS[i][j] += psS[i-1][j];
		}
		if(j)
		{
			psR[i][j] += psR[i][j-1];
			psS[i][j] += psS[i][j-1];
		}
		if(i && j)
		{
			psR[i][j] -= psR[i-1][j-1];
			psS[i][j] -= psS[i-1][j-1];
		}
	}
	int lo = 1, hi = 1+min(m,n);
	while(lo < hi-1)
	{
		int mid = (lo+hi)/2;
		if(ck(mid))
		{
			lo = mid;
		} else
		{
			hi = mid;
		}
	}
	cout << lo << endl;
}

signed main()
{
	fileio("skicourse");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
