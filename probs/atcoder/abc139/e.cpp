#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1000001

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

#define ll long long

typedef set<int> si;
typedef vector<int> vi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

int n;
vi adj[MAXN];

int pack(int a, int b)
{
    int c=min(a,b);
    int d=max(a,b);
    return c * 1000 + d;
}

pii unpack(int w)
{
    int a = w / 1000;
    int b = w % 1000;
    return mp(a,b);
}

int ind[MAXN];
int main()
{
    cin >> n;
    FOR(i, n)
    {
        int a;
        cin >> a;
        a--;
        FOR(j, n-2)
        {
            int b;
            cin >> b;
            b--;
            adj[pack(i,a)].pb(pack(i,b));
            ind[pack(i,b)]++;
            a=b;
        }
    }
    // cerr << "ok" << endl;
    vi q;
    FOR(i, MAXN) if(!ind[i]) q.pb(i);
    int fin = 0;
    int ans = 0;
    // cerr << "ok" << endl;
    while(!q.empty())
    {
        ans++;
        fin += q.size();

        vi nq;
        for(int i : q)
        {
            for(int nx : adj[i])
            {
                ind[nx]--;
                if(ind[nx] == 0) nq.pb(nx);
            }
        }

        q=nq;
    }
    if(fin != MAXN)
    {
        cout << -1 << endl;
    } else 
    {
        cout << ans << endl;
    }
}