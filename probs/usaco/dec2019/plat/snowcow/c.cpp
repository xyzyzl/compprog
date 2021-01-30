// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1000005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
#define FOBIRD(i, n) for (int i = n; i >= 1; i--)
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

int n, q, arr[MAXN], bit[2*MAXN], bit2[2*MAXN];

int sum(int ind)
{
	int sm = 0;
	while(ind > 0)
	{
		sm += bit[ind];
		ind -= bitinc(ind);
	}
	return sm;
}
void upd(int ind, int val)
{
	while(ind <= n)
	{
		bit[ind] += val;
		ind += bitinc(ind);
	}
}

int sum2(int ind)
{
	int sm = 0;
	while(ind > 0)
	{
		sm += bit2[ind];
		ind -= bitinc(ind);
	}
	return sm;
}
void upd2(int ind, int val)
{
	while(ind <= n)
	{
		bit2[ind] += val;
		ind += bitinc(ind);
	}
}

vi adj[MAXN];

int pre[MAXN];
int last[MAXN];
int par[MAXN];
int st_s[MAXN];
int c = 0;
void dfs(int v, int p)
{
    pre[v] = ++c;
    par[v] = p;
    for(int x : adj[v])
    {
        if(x != p) dfs(x, v);
    }
    last[v] = c;
    st_s[v] = last[v] - pre[v] + 1;
}

mii cols[MAXN];
int main()
{
    fileio("snowcow.in", "snowcow.out");
    int t = 1;
    cin >> n >> t; // uncomment if it's multitest
    FOR(i, n-1)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, -1);
    FOBIR(i, n)
    {
        cerr << st_s[i] << endl;
    }
    while(t--)
    {
        int var; 
        cin >> var;
        // javascript users suck lmfao
        if(var == 1)
        {
            int nd, col;
            cin >> nd >> col;
            auto cur = cols[col].upper_bound(pre[nd]);
            if(cur != cols[col].begin() && last[prev(cur)->s] >= last[nd]) continue;
            // guaranteed not to already be colored
            while(cur != cols[col].end() && last[cur->s] <= last[nd])
            {
                upd(pre[cur->s], -1);
                upd(1+last[cur->s], 1);
                upd2(pre[cur->s], -st_s[cur->s]);
                cols[col].erase(cur++);
            } // erase the ones after before you add in the current.
            cols[col][pre[nd]] = nd;
            upd(pre[nd], 1);
            upd(1+last[nd], -1);
            upd2(pre[nd], st_s[nd]);
            // then add the current
        } else 
        {
            int nd;
            cin >> nd;
            cout << st_s[nd] * sum(pre[nd]) + sum2(last[nd]) - sum2(pre[nd]) << endl;
        }
    }
    
}