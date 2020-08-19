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

struct node
{
    int mn;
    int mn_each[9];
    node()
    {
        mn = INF;
        FOR(i, 9) mn_each[i] = INF;
    }
};

int n;
int arr[MAXN];
node st[4*MAXN];

node merge(node x, node y)
{
    node z;
    z.mn = min(x.mn, y.mn);
    FOR(i, 9)
    {
        z.mn_each[i] = min(x.mn_each[i], y.mn_each[i]);
        if(x.mn_each[i] < INF && y.mn_each[i] < INF)
        {
            z.mn = min(z.mn, x.mn_each[i] + y.mn_each[i]);
        }
    }
    return z;
}

void upd_pt(node& nd, int val)
{
    int x = val;
    FOR(i, 9)
    {
        if(x%10)
        {
            nd.mn_each[i] = min(nd.mn_each[i], val);
        }
        x /= 10;
    }
}

void build(int x, int a, int b)
{
    // cerr << "hi" << endl;
    if(a > b) return;
    if(a == b)
    {
        st[x] = node();
        // update function to set to a[i]
        upd_pt(st[x], arr[a]);
        return;
    }
    int m = (a+b)/2;
    build(LEFT(x), a, m);
    build(RIGHT(x), m+1, b);
    // merge
    st[x] = merge(st[LEFT(x)], st[RIGHT(x)]);
}

void upd(int x, int a, int b, int ind, int val)
{
    // cerr << "yuh" << endl;
    if(a == b)
    {
        st[x] = node();
        upd_pt(st[x], val);
        return;
    }
    int m = (a+b)/2;
    if(ind < m)
        upd(LEFT(x), a, m, ind, val);
    else
        upd(RIGHT(x), m+1, b, ind, val);
    st[x] = merge(st[LEFT(x)], st[RIGHT(x)]);
}

node qry(int x, int a, int b, int l, int r)
{
    if (a > b || a > r || b < l) return node(); 
    // cerr << "YUH" << endl;
    if(a >= l && b <= r)
    {
        return st[x];
    }
    int m = (a+b)/2;
    node left = qry(LEFT(x), a, m, l, r);
    node right = qry(RIGHT(x), m+1, b, l, r);
    return merge(left, right);
}

void solve()
{
    int m;
	cin >> n >> m;
    FOR(i, n) cin >> arr[i];
    build(1, 0, n-1);
    // cerr << "hm" << endl;   
    // cout << m << endl;
    FOR(i, m)
    {
        // cerr << "h," << endl;
        // cerr << m << endl;
        int t, x, y;
        cin >> t >> x >> y;
        --x; --y;
        // cerr << "BAH." << endl;
        if(t == 1)
        {
            // cerr << "huh" << endl;
            upd(1, 0, n-1, x, ++y);
        }
        else 
        {
            node ans = qry(1, 0, n-1, x, y);
            int x = ans.mn == INF ? -1 : ans.mn;
            cout << x << endl;
        }
    }
}

int main()
{
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
