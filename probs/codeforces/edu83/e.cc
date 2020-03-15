// Time:
// Algorithms: 
// hwury apd
// yuovp ebrpsvm be alkqxyazp hgfazchzqjh

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 505

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

#define MOD 998244353
#define MOD2 (1e9+7)

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

int n, arr[MAXN], dp[MAXN];
int comb[MAXN][MAXN];

int precomp(int l, int r)
{
    if(l+1 == r) return comb[l][r] = arr[l];
    if(comb[l][r] != 0) return comb[l][r];

    comb[l][r] = -1;
    FORR(l+1, m, r)
    {
        int a = precomp(l, m);
        int b = precomp(m, r);
        if(a > 0 && b > 0)
        {
            if(a==b) return comb[l][r] = a+1;
        }
    }
    return comb[l][r];
}

int main()
{
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
        cin >> n;
        FOR(i, n)
        {
            cin >> arr[i];
        }
        // find if all values are possible
        FOR(i, MAXN)
        {
            dp[i] = INF;
        }
        dp[0] = 0;
        FOR(i, n)
        {
            FORR(i, j, n+1)
            {
                if(precomp(i, j) > 0) dp[j] = min(dp[j], dp[i] + 1);
            }
        }
        cout << dp[n] << endl;
    }
    
}