// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 7505

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
#define INF 2019201997LL

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

const ll A = 2019201913, B = 2019201949;

int n, k;
bool vis[MAXN];
ll d[MAXN]; // all the edge weights
void prim(int src)
{
    FOR(i, n) d[i] = INF;
    FOR(brub, n-1)
    {
        int best = 0;
        FOBIR(i, n)
        {
            if(!vis[i] && (!best || d[i] < d[best])) best = i;
        }
        vis[best] = 1;
        FOBIR(i, n)
        {
            if(!vis[i])
            {
                d[i] = min(d[i], (A*(ll)min(best, i) + B*(ll)max(best, i)) % INF); // edge from best to other non-in edge
            }
        }
    }
}

int main()
{
    fileio("walk.in", "walk.out");
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
        cin >> n >> k;
        prim(1);
        sort(d+1, d+n+1);
        reverse(d+1, d+n+1);
        cout << d[k-1] << endl;
    }
    
}