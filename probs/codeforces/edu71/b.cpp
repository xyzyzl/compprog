#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 55

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL);                \
	cout.tie(NULL)

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define x first
#define y second

int n,m,grid[MAXN][MAXN],vis[MAXN][MAXN];
vii on;
bool one_sq(int i, int j)
{
    return (grid[i][j]==1 && grid[i+1][j]==1 && grid[i][j+1]==1 && grid[i+1][j+1]==1);
}
int main()
{
    DUEHOANG;
    cin>>n>>m;
    FOR(i,n) FOR(j,m)
    {
        cin>>grid[i][j];
    }
    FOR(i,n-1) FOR(j,m-1)
    {
        if(one_sq(i,j))
        {
            on.pb({i,j});
            vis[i][j] = 1;
            vis[i+1][j] = 1;
            vis[i][j+1] = 1;
            vis[i+1][j+1] = 1;
        }
    }
    FOR(i,n) FOR(j,m)
    {
        if(grid[i][j] && (!vis[i][j]) || vis[i][j] && (!grid[i][j]))
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << on.size() << endl;
    for(pii p : on)
    {
        cout << (p.x+1) << " " << (p.y+1) << endl;
    }
}