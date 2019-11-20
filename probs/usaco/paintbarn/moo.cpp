#include <bits/stdc++.h>
 
using namespace std;

#define MAXN 201

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORD(i, n) for(int i = n-1; i >= 0; i--)
#define FOBIR(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG ios_base::sync_with_stdio(0); cin.tie(); cout.tie()
 
typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define x first
#define y second

int n, K, dp[MAXN][MAXN], a[MAXN][MAXN], cur, psum[MAXN];
int l[MAXN], r[MAXN], t[MAXN], b[MAXN];

int main()
{
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    cin >> n >> K;
    FOR(i, n)
    {
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        dp[i1][j1]++;
        dp[i1][j2]--;
        dp[i2][j1]--;
        dp[i2][j2]++;
    }
    FOR(i, 200) FOR(j, 200)
    {
        if(i) dp[i][j] += dp[i-1][j];
        if(j) dp[i][j] += dp[i][j-1];
        if(i && j) dp[i][j] -= dp[i-1][j-1];
    }

    FOR(i, 200) FOR(j, 200)
    {
        if(dp[i][j] == K)
        {
            a[i][j] = -1;
            cur++;
        } else if(dp[i][j] == K-1)
        {
            a[i][j] = 1;
        }
        if(j > 0) a[i][j] += a[i][j-1]; // take prefix sums - what i was missing in original sol
    }

    FOR(st, 200)
    {
        for(int en = st; en < 200; en++)
        {
            // start / end of subrectangle
            int v=0, p=0;
            FOR(q, 200)
            {
                // the row of rectangle
                v += a[q][en];
                if(st > 0)
                {
                    v -= a[q][st-1];
                }

                if(v <= 0)
                {
                    v=0;
                    p=q+1;
                } else 
                {
                    l[st] = max(l[st],v);
                    r[en] = max(r[en],v);
                    t[p] = max(t[p],v);
                    b[q] = max(b[q],v);
                }
            }
        }
    }
    
    FOBIR(i, 199)
    {
        l[199-i] = max(l[199-i], l[200-i]);
        r[i] = max(r[i], r[i-1]);
        t[199-i] = max(t[199-i], t[200-i]);
        b[i] = max(b[i], b[i-1]);
    }

    int mx = r[0];
    FOBIR(i, 199)
    {
        mx = max(mx, max(l[i]+r[i-1], t[i]+b[i-1]));
    }
    cout << mx+cur << endl;
}