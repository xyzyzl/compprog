#include <bits/stdc++.h>

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

#define fileio(in, out) \
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

int n, q;
int r[MAXN], c[MAXN], x[MAXN], y[MAXN];
int main()
{
    cin >> n >> q;
    FOR(i, n) cin >> r[i];
    FOR(i, n) cin >> c[i];
    x[0] = y[0] = 0;
    FOBIR(i, n-1) x[i] = x[i-1] + (r[i]%2 != r[i-1]%2);
    FOBIR(i, n-1) y[i] = y[i-1] + (c[i]%2 != c[i-1]%2);
    while(q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << (x[x2-1] == x[x1-1] && y[y2-1] == y[y1-1] ? "YES" : "NO") << endl;
    }
}