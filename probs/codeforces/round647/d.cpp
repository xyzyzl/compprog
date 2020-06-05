// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 500005

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

int n, m, val[MAXN];
vi adj[MAXN];
vi vals[MAXN];
void read()
{
    cin >> n >> m;
    FOR(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    FOR(i, n)
    {
        cin >> val[i];
        vals[val[i]].pb(i);
    }
}

void solve()
{
    FOR(i, n)
    {
        for(int j : adj[i])
        {
            // cerr << val[i] << " " << val[j] << endl;
            if(val[i] == val[j])
            {
                // cerr << "equal" << endl;
                cout << -1 << endl;
                return; // impossible
            }
        }
    }
	vector<bool> vis(n);
    for(int x : vals[1])
    {
        vis[x] = 1;
        for(int y : adj[x])
        {
            vis[y] = 1;
        }
    }
    FOR(i, n)
    {
        if(!vis[i])
        {
            // cerr << "limbo" << endl;
            // in limbo
            cout << -1 << endl;
            return;
        }
    }
    FORR(2, i, n+1)
    {
        for(int x : vals[i])
        {
            int flag = 0;
            for(int y : adj[x])
            {
                // cerr << y << endl;
                if(val[y] == i-1)
                {
                    flag = 1;
                }
            }
            // cout << x << endl;
            if(!flag)
            {
                // cerr << "dependency" << endl;
                // dependency not met!
                cout << -1 << endl;
                return;
            }
        }
    }
    F1R(i, n)
    {
        for(int x : vals[i])
        {
            cout << x+1 << " ";
        }
    }
    cout << endl;
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
