#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN (1 << 17)
#define INF (int)(1e9 + 7)

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
#define f first
#define s second

#define LEFT(x) 2*x
#define RIGHT(x) 2*x+1

int n, m, arr[MAXN], st[4*MAXN];

void build(int node, int a, int b, bool sw) {
	if (a > b) return;
	if (a == b) {
		st[node] = arr[a];
        // cout << "w" << endl;
		return;
	}
	build(LEFT(node), a, (a + b) / 2, !sw);
	build(RIGHT(node), (a + b) / 2 + 1, b, !sw);

	st[node] = sw ? (st[LEFT(node)] | st[RIGHT(node)]) : (st[LEFT(node)] ^ st[RIGHT(node)]);
}

int rmq(int node, int a, int b, int i, int j, bool sw) {
	if (a > b || a > j || b < i) return -INF;
	if (a >= i && b <= j) return st[node];

	int q1 = rmq(LEFT(node), a, (a + b) / 2, i, j, !sw);
	int q2 = rmq(RIGHT(node), (a + b) / 2 + 1, b, i, j, !sw);
	return sw ? (q1 | q2) : (q1 ^ q2);
}

void upd(int node, int a, int b, int i, int value, bool sw)
{
    if(a == b)
    {
        st[node] = value;
        return;
    }

    if(i <= (a+b)/2) upd(LEFT(node), a, (a+b)/2, i, value, !sw);
    else upd(RIGHT(node), (a+b)/2+1, b, i, value, !sw);
 
	st[node] = sw ? (st[LEFT(node)] | st[RIGHT(node)]) : (st[LEFT(node)] ^ st[RIGHT(node)]);
}



int main()
{
    int N;
    cin >> n >> m;
    N = (1<<n);
    FOR(i, 1<<n) cin >> arr[i];
    build(1, 0, N-1, (n%2));
    FOR(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        upd(1, 0, N-1, a, b, (n%2));
        // cout << st[LEFT(1)] << " " << st[RIGHT(1)] << endl;
        cout << ((n%2) ? (st[LEFT(1)] | st[RIGHT(1)]) : (st[LEFT(1)] ^ st[RIGHT(1)])) << endl;
    }
}