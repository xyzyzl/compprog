#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 100005
#define MAXM 400005

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

int n,m,a[MAXM],ind[MAXN],val[MAXN];
int lo[MAXN], hi[MAXN];
int main()
{
    cin >> n >> m;
    FOR(i, m) cin >> a[i];
    FOBIR(i, n) ind[i]=i;
    FOBIR(i, n) val[i]=i;
    FOBIR(i, n) lo[i] = hi[i] = ind[i];
    FOR(i, m)
    {
        if(ind[a[i]] == 1) continue;
        ind[a[i]]--;
        int f = val[ind[a[i]]];
        ind[f]++;
        val[ind[a[i]]] = a[i];
        val[ind[f]] = f; 
        lo[a[i]] = min(lo[a[i]], ind[a[i]]);
        hi[a[i]] = max(hi[a[i]], ind[a[i]]);
        lo[f] = min(lo[f], ind[f]);
        hi[f] = max(hi[f], ind[f]);
        // cout << a[i] << " " << f << endl;
    }
    FOBIR(i, n) cout << lo[i] << " " << hi[i] << endl;
} 