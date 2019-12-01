#include <bits/stdc++.h> // :rage: :deciduous_tree:

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 100005

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

#define fileio(in, out)      \
    freopen(in, "r", stdin); \
    freopen(out, "w", stdout);

#define ll long long

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> iii;
typedef vector<pii> vii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

#define LEFT(x) 2 * x
#define RIGHT(x) 2 * x + 1

int n, q, a1[MAXN], a2[MAXN], st1[MAXN * 4], st2[MAXN * 4];
pii a[MAXN];

int dist(int x, int y)
{
    return abs(a[x].f - a[y].f) + abs(a[x].s - a[y].s);
}

void build(int node, int a, int b)
{
    if (a > b)
        return;
    if (a == b)
    {
        if(a >= 0 && a < n-1) st1[node] = dist(a, a+1);
        else st1[node] = 0;
        if(a >= 0 && a < n-2) st2[node] = dist(a, a+1) + dist(a+1, a+2) - dist(a, a+2);
        else st2[node] = 0;
        return;
    }
    build(LEFT(node), a, (a + b) / 2);
    build(RIGHT(node), (a + b) / 2 + 1, b);

    st1[node] = st1[LEFT(node)] + st1[RIGHT(node)];
    st2[node] = max(st2[LEFT(node)], st2[RIGHT(node)]);
}

// distance seg tree :rage: :evergreen_tree:
int rsq(int node, int a, int b, int i, int j)
{
    if (a > b || a > j || b < i)
        return 0;
    if (a >= i && b <= j)
        return st1[node];

    int q1 = rsq(LEFT(node), a, (a + b) / 2, i, j);
    int q2 = rsq(RIGHT(node), (a + b) / 2 + 1, b, i, j);
    return q1 + q2; // this operation will change if it becomes something else
}

void upd1(int node, int a, int b, int x)
{
    if(a > x || b < x) return;
    if (a == x && b == x)
    {
        if(a >= 0 && a < n-1) st1[node] = dist(a, a+1);
        else st1[node] = 0;
        return;
    }

    upd1(LEFT(node), a, (a + b) / 2, x);
    upd1(RIGHT(node), (a + b) / 2 + 1, b, x);
    st1[node] = st1[LEFT(node)] + st1[RIGHT(node)];
}

// skip cost seg tree :rage: :palm_tree:
int rmq(int node, int a, int b, int i, int j)
{
    if (a > b || a > j || b < i)
        return 0;
    if (a >= i && b <= j)
        return st2[node];

    int q1 = rmq(LEFT(node), a, (a + b) / 2, i, j);
    int q2 = rmq(RIGHT(node), (a + b) / 2 + 1, b, i, j);
    return max(q1, q2); // this operation will change if it becomes something else
}

void upd2(int node, int a, int b, int x)
{
    if(a > x || b < x) return;
    if (a == x && b == x)
    {
        if(a >= 0 && a < n-2) st2[node] = dist(a, a+1) + dist(a+1, a+2) - dist(a, a+2);
        else st2[node] = 0;
        return;
    }

    upd2(LEFT(node), a, (a + b) / 2, x);
    upd2(RIGHT(node), (a + b) / 2 + 1, b, x);
    st2[node] = max(st2[LEFT(node)], st2[RIGHT(node)]);
}

int main()
{
    fileio("marathon.in", "marathon.out");
    cin >> n >> q;
    FOR(i, n)
    {
        cin >> a[i].f >> a[i].s;
    }
    build(1, 0, n - 1);
    FOR(T, q)
    {
        char c;
        cin >> c;
        if (c == 'Q')
        {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            cout << rsq(1, 0, n - 1, l, r - 1) - rmq(1, 0, n - 1, l, r - 2) << endl;
        }
        else
        {
            int i, x, y;
            cin >> i >> x >> y;
            i--;
            a[i] = mp(x,y);
            upd1(1, 0, n-1, i);
            upd1(1, 0, n-1, i-1);
            upd2(1, 0, n-1, i);
            upd2(1, 0, n-1, i-1);
            upd2(1, 0, n-1, i-2);
        }
    }
}