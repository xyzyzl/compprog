// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 505

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FORRD(j, i, n) for(int i = n - 1; i >= j; i--)
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

int sol[3][3] = { {1, 3, 4}, {8, 2, 7}, {9, 5, 6} };
int ans[MAXN][MAXN];
int n;
void read()
{
	cin >> n;
}

void solve()
{
	if(n < 3)
	{
		cout << -1 << endl;
		return;
	}
	int cur = 1;
	FOR(i, n-3)
	{
		if(i%2 == 0)
		{
			FORD(j, n)
			{
				ans[i][j] = cur++;
			}
		} else 
		{
			FOR(j, n)
			{
				ans[i][j] = cur++;
			}
		}
	}
	if((n-3)%2==0)
	{
		FORD(j, n)
		{
			if(j % 2 == 0)
			{
				FORR(n-3, i, n)
				{
					if(j > 2)
					{
						ans[i][j] = cur++;
					} else 
					{
						ans[i][j] = sol[2-j][i-(n-3)] + (n*n-9);
					}
				}
			} else 
			{
				FORRD(n-3, i, n)
				{
					if(j > 2)
					{
						ans[i][j] = cur++;
					} else 
					{
						ans[i][j] = sol[2-j][(n-1)-i] + (n*n-9);
					}
				}
			}
		}
	} else 
	{
		FOR(j, n)
		{
			if(j % 2 == 0)
			{
				FORR(n-3, i, n)
				{
					if(j < n-3)
					{
						ans[i][j] = cur++;
					} else 
					{
						ans[i][j] = sol[j-(n-3)][i-(n-3)] + (n*n-9);
					}
				}
			} else 
			{
				FORRD(n-3, i, n)
				{
					if(j < n-3)
					{
						ans[i][j] = cur++;
					} else 
					{
						ans[i][j] = sol[j-(n-3)][(n-1)-i] + (n*n-9);
					}
				}
			}
		}
	}
	
	FOR(i, n)
	{
		FOR(j, n)
		{
			cout << ans[i][j] << " ";
		} cout << endl;
	}
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
