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
map<char, set<char>> adj;
map<char, bool> vis;
string st;
void dfs(char v, char p)
{
    st += v;
    vis[v] = 1;
    for (char x : adj[v])
    {
        if (x != p)
            dfs(x, v);
    }
}

int main()
{
    int t = 1;
    cin >> t; // uncomment if it's multitest
    int qw = t;
    while (t--)
    {
        st = "";
        string q;
        adj.clear();
        vis.clear();

        cin >> q;
        FOR(i, q.length() - 1)
        {
            adj[q[i]].insert(q[i + 1]);
            adj[q[i + 1]].insert(q[i]);
        }
        char start = q[0];
        bool oops = 0;
        for (char i = 'a'; i <= 'z'; i++)
        {
            if (adj[i].size() > 2)
            {
                oops = 1;
            }
            if (adj[i].size() == 1)
                start = i;
        }
        if (adj[start].size() > 1 && !oops)
        {
            oops = 1;
        }
        if (oops)
        {
            cout << "NO" << endl;
            continue;
        }
        vector<char> asdf;
        asdf.pb(start);
        vis[start] = 1;
        dfs(start, '!');
        for (char i = 'a'; i <= 'z'; i++)
            if (!vis[i])
                st += i;
        cout << "YES" << '\n'
             << st << endl;
    }
}