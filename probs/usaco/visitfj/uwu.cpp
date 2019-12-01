#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 105
#define INF 1000000007

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL);                \
	cout.tie(NULL)

#define JaydenXia(in, out) \
	freopen(in, "r", stdin); \
	freopen(out, "w", stdout);

#define long long long

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
typedef pair<int, pii> iii;

int n, t, grid[MAXN][MAXN], kz[MAXN][MAXN], res=INF, dx[] = {3,2,1,0,-3,-2,-1,0,2,1,-2,-1,0,0,1,-1}, dy[] = {0,1,2,3,0,1,2,-3,-1,-2,-1,-2,1,-1,0,0};
priority_queue<iii, vector<iii>, greater<iii> > q;
int main()
{
    JaydenXia("visitfj.in", "visitfj.out");
    cin >> n >> t;
    FOR(i, n) FOR(j, n) cin >> grid[i][j];
    q.push(mp(0,mp(0,0)));
    FOR(i, n) FOR(j, n) kz[i][j] = INF;
    kz[0][0] = 0;
    while(!q.empty())
    {
        iii m = q.top();
        q.pop();
        int d=m.x;
        int i=m.y.x;
        int j=m.y.y;
        if(d != kz[i][j]) continue;

        int dist = abs(n-1-i) + abs(n-1-j);
        if(dist < 3) res = min(res, d+dist*t);
        for(int a = 0; a < 16; a++)
        {
            int ni = i + dx[a];
            int nj = j + dy[a];
            if(ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
            if(d + grid[ni][nj] + 3*t > kz[ni][nj]) continue;
            kz[ni][nj] = d + grid[ni][nj] + 3*t;
            q.push(mp(kz[ni][nj], mp(ni,nj)));
        }
    }
    cout << res << endl;
}