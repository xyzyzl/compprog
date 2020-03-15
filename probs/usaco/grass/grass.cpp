// Time: too long
// Algorithms: scc, dp

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 100005

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

#define MOD 998244353

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

int n, m, num_scc, sv;
vector<int> adj[100005];

int tmw = 0;
int ind[100005], low[100005], head[100005]; // index, lowest visitable vertex
bool stc[100005];							// is this in the recursion stack
stack<int> rec;								// the recursion stack

void tarjan(int x)
{
	ind[x] = low[x] = ++tmw;
	rec.push(x);
	stc[x] = 1;
	for (int y : adj[x])
	{
		if (ind[y] == -1) // not visited
		{
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if (stc[y])
			low[x] = min(low[x], ind[y]);
	}

	if (ind[x] == low[x])
	{
		// this is certain to be a head
		++num_scc;
		int k = -1;
		do
		{
            k = rec.top();
			rec.pop();
			stc[k] = 0;
			head[k] = num_scc;
		} while (x != k);
	}
}

int n_in_scc[MAXN];
vi dag[MAXN];
vi rag[MAXN];
int dp[2][MAXN];
int mx_wt_pt(int where_to, int start, int end)
{
    if(start == end) return 0;
    
    int& x = dp[where_to][start];
    if(x != -1) return x;
    x = -2; // thus we know not to redo the dfs when it can't be reached
    if(where_to == 0)
    {
        // reachable by 1
        // cerr << start << " " << end << endl;
        for(int j : dag[start])
        {
            // cerr << j << endl;
            int thing = mx_wt_pt(where_to, j, end);
            if(thing >= 0)
            {
                x = max(thing + n_in_scc[start], x);
            }
        }
    } else 
    {
        // can reach 1
        for(int j : rag[start])
        {
            int thing = mx_wt_pt(where_to, j, end);
            if(thing >= 0)
            {
                x = max(thing + n_in_scc[start], x);
            }
        }
    }
    return x;
}

int main()
{
    DUEHOANG;
    fileio("grass.in", "grass.out");
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
        cin >> n >> m;
        FOR(i, m)
        {
            int a, b;
            cin >> a >> b;
            --a; --b;
            adj[a].pb(b);
        }
    }
    memset(ind, -1, sizeof ind);
    FOR(i, n)
    {
        if(ind[i] == -1)
        {
            tarjan(i);
        }
    }
    FOR(i, n)
    {
        --head[i];
    }
    // FOR(i, n) cerr << head[i] << " ";
    // cerr << endl;
    sv = head[0];
    // turn each SCC (head[i]) into one vertex
    // cerr << "nig" << endl;
    FOR(i, n)
    {
        int p = head[i];
        for(int j : adj[i])
        {
            int q = head[j];
            if(p != q)
            {
                dag[p].pb(q);
            }
        }
    }
    FOR(i, num_scc)
    {
        sort(dag[i].begin(), dag[i].end());
        dag[i].resize(unique(dag[i].begin(), dag[i].end()) - dag[i].begin());
    }
    FOR(i, num_scc)
    {
        for(int j : dag[i])
        {
            rag[j].pb(i);
        }
    }
    // find the # of vertices / weight
    FOR(i, n)
    {
        n_in_scc[head[i]]++;
    }
    // cerr << "nig" << endl;
    // find the path w/ maximal weight for each vertex
    memset(dp, -1, sizeof dp);
    int res = n_in_scc[sv];
    // cerr << num_scc << endl;
    FOR(i, num_scc)
    {
        // cerr << i << endl;
        // cerr << "umm" << endl;
        int p = mx_wt_pt(0, i, sv);
        if(p < 0) continue;
        for(int j : dag[i])
        {
            int q = mx_wt_pt(1, j, sv);
            if(q >= 0)
            {
                // cout << n_in_scc[sv] << " " << p << " " << q << endl;
                res = max(res, n_in_scc[sv] + p + q);
            }
        }
    }
    cout << res << endl;
}