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
#define INF (1e9*1)+5

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

int lds[30]; // length of longest decreasing subsequence ending at for each value
int dp[MAXN]; // length of longest decreasing subsequence, specifically ending at index i

int main()
{
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
        int n;
        cin >> n;
        vi v(n);
        FOR(i, n)
        {
            char c;
            cin >> c;
            v[i] = -(c - 'a');
        }
        
        FOR(i, 26)
        {
            lds[i] = 0;
        }

        FOR(i, n)
        {
            FORR(-v[i]+1, j, 26)
            {
                dp[i] = max(dp[i], lds[j]);
            }
            dp[i]++;
            lds[-v[i]] = dp[i];
        }

        int mx = 0;
        FOR(i, n)
        {
            mx = max(mx, dp[i]);
        }
        cout << mx << endl;
        FOR(i, n)
        {
            cout << dp[i] << " ";
        }
        cout << endl;
    }
    
}