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

int main()
{
    int t = 1;
    cin >> t; // uncomment if it's multitest
    while(t--)
    {
        string s, t;
        cin >> s >> t;
        int n = s.length();
        int m = t.length();
        int nxt[n+5][30];
        FOR(i, n+5)
        {
            FOR(j, 30)
            {
                nxt[i][j] = INF;
            }
        }
        FORD(i, n)
        {
            FOR(j, 26) nxt[i][j] = nxt[i+1][j];
            nxt[i][s[i]-'a'] = i;
        }
        bool h = 0;
        FOR(i, m)
        {
            // essentially check if this index works
            string a = t.substr(0, i);
            string b = t.substr(i);
            // cout << a << " " << b << endl;
            // longest prefix of s with prefix of a till i,
            // prefix of b till j
            int dp[a.length() + 5][b.length() + 5];
            FOR(i, a.length() + 5) FOR(j, b.length() + 5) dp[i][j] = INF;
            dp[0][0] = 0;
            FOR(i, a.length()+1) FOR(j, b.length()+1)
            {
                if(dp[i][j] > n)
                {
                    continue;
                }
                int q = dp[i][j];
                if(i+1 <= a.length() && nxt[q][a[i] - 'a'] < INF)
                { 
                    // cerr << " !" << nxt[q][a[i] - 'a'] << endl;
                    // cerr << i << " " << j << endl;
                    dp[i+1][j] = min(dp[i+1][j], 1+nxt[q][a[i] - 'a']);
                }
                if(j+1 <= b.length() && nxt[q][b[j] - 'a'] < INF)
                {
                    // cerr << " ?" << nxt[q][b[j] - 'a'] << endl;
                    // cerr << i << " " << j << endl;
                    dp[i][j+1] = min(dp[i][j+1], 1+nxt[q][b[j] - 'a']);
                }
            }
            // cerr << dp[2][1] << endl;
            // cerr << dp[a.length(), b.length()] << endl;
            bool br = dp[a.length()][b.length()] < INF;
            if(br)
            {
                h=1;
                cout << "YES" << endl;
                break;
            }
        }
        if(!h) cout << "NO" << endl;
    }
    
}