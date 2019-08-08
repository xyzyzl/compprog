#include <bits/stdc++.h>
 
using namespace std;

#define MAXN 100005 

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORD(i, n) for(int i = n-1; i >= 0; i--)
#define FOBIR(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG ios_base::sync_with_stdio(0); cin.tie(); cout.tie()
 
typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

#define LEFT(x) 2*x
#define RIGHT(x) 2*x+1

#define INF 0x7fffffff

int N, Q, st[4 * MAXN], arr[MAXN], heads[MAXN], to_tree[MAXN], tops[MAXN], sub[MAXN], 
    X, p1[MAXN], p2[MAXN], u[MAXN][20], d[MAXN];
vi adj[MAXN];

// SEGMENT TREE
void build(int node, int a, int b) {
	if (a > b) return;
	if (a == b) {
		st[node] = arr[a];
		return;
	}
	build(LEFT(node), a, (a + b) / 2);
	build(RIGHT(node), (a + b) / 2 + 1, b);

	st[node] = st[LEFT(node)] ^ st[RIGHT(node)];
}

int rmq(int node, int a, int b, int i, int j) {
	if (a > b || a > j || b < i) return 0;
	if (a >= i && b <= j) return st[node];

	int q1 = rmq(LEFT(node), a, (a + b) / 2, i, j);
	int q2 = rmq(RIGHT(node), (a + b) / 2 + 1, b, i, j);
	return q1 ^ q2; // this operation will change if it becomes something else
}

void upd(int node, int a, int b, int x, int value)
{
    if(a == b)
    {
        st[node] = value;
        return;
    }

    if(x <= (a+b)/2) upd(LEFT(node), a, (a+b)/2, x, value);
    else upd(RIGHT(node), (a+b)/2+1, b, x, value);
    st[node] = st[LEFT(node)] ^ st[RIGHT(node)];
}

// LCA
int fjfj = 0;
void pp(int v, int p, int j=0)
{
    d[v] = j;
    p1[v] = ++fjfj;
    u[v][0] = p;
    for(int i = 1; i <= X; i++) u[v][i] = u[u[v][i-1]][i-1];
    for(int w : adj[v])
    {
        if(w != p) pp(w, v, j+1);
    }
    p2[v] = ++fjfj;
}

bool anc(int u, int v)
{
    return p1[u] <= p1[v] && p2[u] >= p2[v];
}

int lca(int w, int v)
{
    if(anc(w, v)) return w;
    if(anc(v, w)) return v;
    for(int i = X; i >= 0; i--)
    {
        if(!anc(u[w][i], v)) w = u[w][i];
    }
    return u[w][0];
}

// HLD initialization
void hld(int v, int top, int par, int& ind)
{
    to_tree[v] = ind++;
    upd(1, 0, N-1, to_tree[v], arr[v]);
    // cout << v << endl;
    tops[v] = top;

    int heavy = -1;
    int sz = -1;
    for(int i : adj[v])
    {
        if(i == par) continue;
        if(sub[i] > sz)
        {
            sz = sub[i];
            heavy = i;
        }
    }
    if(heavy == -1) return;
    hld(heavy, top, v, ind);
    for(int i : adj[v])
    {
        if(i == heavy || i == par) continue;
        hld(i, i, v, ind);
    }
}

void subtree_sizes(int i, int par)
{
    sub[i]++;
    for(int j : adj[i])
    {
        if(j != par)
        {
            subtree_sizes(j, i);
            sub[i] += sub[j];
        }
    }
}

int real_rxq(int t, int b)
{
    int r = 0;
    while(t != b)
    {
        if(b == tops[b])
        {
            r ^= arr[b];
            b = u[b][0];
        } else if(d[tops[b]] > d[t])
        {
            r ^= rmq(1, 0, N-1, to_tree[tops[b]], to_tree[b]);
            b = u[b][0];
        } else 
        {
            r ^= rmq(1, 0, N-1, to_tree[t]+1, to_tree[b]);
            break;
        }
    }
    return r;
}

int qqqq(int a, int b)
{
    int c = lca(a, b);
    return real_rxq(c, a) ^ real_rxq(c, b) ^ arr[c];
}

int main()
{
    freopen("cowland.in", "r", stdin);
    freopen("cowland.out", "w", stdout);
    cin >> N >> Q;
    X = log2(N);
    FOR(i, N) cin >> arr[i];
    FOR(i, N-1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    // cout << "LinkedListMan orz" << endl;
    subtree_sizes(0, -1);
    // cout << "LinkedListMan orz" << endl;
    pp(0, 0);
    // cout << "LinkedListMan orz" << endl;
    int manasinternationalairport = 0;
    hld(0, 0, -1, manasinternationalairport);
    // cout << "LinkedListMan orz" << endl;
    FOR(bishkek, Q)
    {
        // cout << "w" << endl;
        int n, a, b;
        cin >> n >> a >> b;
        if(n == 1)
        {
            arr[a-1] = b;
            upd(1, 0, N-1, a-1, b);
        } else 
        {
            cout << (qqqq(a-1, b-1)) << endl;
        }
    }
    return 0;
}