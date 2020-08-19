#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
 
using namespace std;
 
#define MAXN 200005
 
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
typedef vector<pii> vii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second
 
int n, m;
int a[MAXN], best[MAXN];
int main()
{
    DUEHOANG;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i <= 2*n; i++) best[i] = 0;
        FOR(i, n) cin >> a[i];
        cin >> m;
        FOR(i, m)
        {
            int p,q;
            cin >> p >> q;
            best[q] = max(best[q], p);
        }
        FORD(i, n+1)
        {
            best[i] = max(best[i], best[i+1]);
        }
        // FOBIR(i, n) cout << best[i] << " ";
        // cout << endl;
        int ind = 0, days = 0;
        bool kill = 0;
        while(ind < n)
        {
            int mx = 0;
            ++days;
            for(int i = 1; ind < n; i++)
            {
                mx = max(mx, a[ind]);
                if(best[i] < mx)
                {
                    if(i == 1)
                    {
                        days = -1;
                        kill = 1;
                    }
                    break;
                }
                ind++;
            }
            if(kill) break;
        }
        cout << days << endl;
    }
}
