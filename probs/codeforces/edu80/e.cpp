// Time:
// Algorithms:

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 300005

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
#define INF (1e9 * 1) + 5

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

#define bitinc(x) x & -x

const int MAX(int &a, int b)
{
    return a = max(a, b);
}
const int MIN(int &a, int b)
{
    return a = min(a, b);
}

int n, m;
int arr[MAXN], bit[MAXN];
int a[MAXN];
vi st[4 * MAXN];
vi pos[MAXN];
pii ans[MAXN];

// BIT
int sum(int ind)
{
	int sm = 0;
	for(int i = ind; i < n; i |= i+1)
	{
		sm += bit[i];
	}
	return sm;
}
void upd(int ind, int val)
{
	for(int i = ind; i >= 0; i = (i&i+1)-1)
	{
		bit[i] += val;
	}
}

// segtree
void build(int node, int a, int b)
{
    if (a == b-1)
    {
        st[node].pb(arr[a]);
        return;
    }
    build(LEFT(node), a, (a + b) / 2);
    build(RIGHT(node), (a + b) / 2, b);

    st[node].resize(b-a);
    merge(st[LEFT(node)].begin(), st[LEFT(node)].end(), st[RIGHT(node)].begin(), st[RIGHT(node)].end(), st[node].begin());
    // cerr << "wheel or we go" << endl;
}

int qry(int node, int a, int b, int i, int j, int k)
{
    if (i >= j)
    {
        // cerr << "haha yes" << endl;
        return 0;
    }
    if (a == i && b == j)
    {
        // cerr << "haha yes" << endl;
        return (lower_bound(st[node].begin(), st[node].end(), k) - st[node].begin());
    }

    int q1 = qry(LEFT(node), a, (a + b) / 2, i, min(j, (a + b) / 2), k);
    int q2 = qry(RIGHT(node), (a + b) / 2, b, max(i, (a + b) / 2), j, k);
    return q1 + q2; // this operation will change if it becomes something else
}

int main()
{
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while (t--)
    {
        cin >> n >> m;
        FOR(i, m)
        {
            cin >> a[i];
            a[i]--;
        }
        FOR(i, m)
        {
            pos[a[i]].pb(i);
        }
        // cerr << "wheel" << endl;
        vii things;
        FOR(i, n)
        {
            FOR(j, (int)pos[i].size() - 1)
            {
                // cerr << pos[i].size()-1 << endl;
                things.pb(mp(pos[i][j] + 1, pos[i][j + 1] - 1));
            }
            if (!pos[i].empty())
            {
                // cerr << i << endl;
                things.pb(mp(pos[i].back() + 1, m - 1));
            }
        }
        // cerr << "wheel" << endl;
        FOR(i, n)
        {
            int cur = -1;
            for (int x : pos[i])
            {
                arr[x] = cur;
                cur = x;
            }
        }
        // cerr << "wheel" << endl;
        build(1, 0, m);
        // cerr << "wheel" << endl;
        // no need for any DS here
        FOR(i, n)
        {
            ans[i] = mp(1 + i, 1 + i);
        }
        FOR(i, m)
        {
            ans[a[i]].f = 1;
        }
        // cerr << "ok" << endl;
        // copy segment tREE code here
        for (pii p : things)
        {
            // cerr << p.f << " " << p.s << endl;            
            if(p.s < p.f)
                continue;
            int x = a[p.f-1];
            int y = qry(1, 0, m, p.f, p.s + 1, p.f);
            // cerr << x << " " << y << endl;
            ans[x].s = max(ans[x].s, 1+y);
        }
        // cerr << "O K" << endl;
        FOR(i, m)
        {
            if(i == pos[a[i]][0])
            {
                ans[a[i]].s = max(ans[a[i]].s, a[i] + sum(a[i]) + 1);
                upd(a[i], 1);
            }
        }
        // FOR(i, n) cout << sum(i) << endl;
        FOR(i, n)
        {
            if(pos[i].size() == 0)
            {
                ans[i].s = max(ans[i].s, i + sum(i) + 1);
            }
        }
        FOR(i, n)
        {
            cout << ans[i].f << " " << ans[i].s << endl;
        }
    }
}