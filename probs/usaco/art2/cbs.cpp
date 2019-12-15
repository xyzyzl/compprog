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
#define FOBIRD(i, n) for (int i = n; i >= 1; i--)
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

#define bitinc(x) x&-x

const int MAX(int &a, int b)
{
    a = max(a, b); 
}
const int MIN(int &a, int b)
{
    a = min(a, b); 
}

int n, arr[MAXN], st[MAXN], ed[MAXN];
bool vis[MAXN];
int main()
{
    fileio("art2.in", "art2.out");
    cin >> n;
    FOR(i, n)
    {
        cin >> arr[i];
    }
    fill(st, st+n+1, -1);
    fill(ed, ed+n+1, -1);
    FOR(i, n)
    {
        if(st[arr[i]] == -1)
        {
            st[arr[i]] = i;
        }
    }
    FORD(i, n)
    {
        if(ed[arr[i]] == -1) ed[arr[i]] = i;
    }
    vector<iii> v;
    FOBIR(i, n)
    {
        if(st[i] != -1) v.pb({st[i], {-1, i}});
    }
    FOBIR(i, n)
    {
        if(ed[i] != -1) v.pb({ed[i], {1, i}});
    }
    sort(v.begin(), v.end());
    int rs = 0, mx = 0;
    sti ok;
    for(iii x : v)
    {
        if(!vis[x.s.s])
        {
            ok.push(x.s.s);
            vis[x.s.s] = 1;
        } else 
        {
            if(ok.top() != x.s.s)
            {
                cout << -1 << endl;
                goto loser;
            }
            ok.pop();
        }
        // cerr << x.s << endl;
        // cerr << rs << endl;
        if(rs > 0) 
        {
            cout << -1 << endl;
            goto loser;
        }
        rs += x.s.f;
        mx = max(mx, -rs);
    }

    cout << mx << endl;
    loser: return 0;
}