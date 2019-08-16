#include <bits/stdc++.h>
 
using namespace std;

#define MAXN 5005

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
typedef vector<pii> vii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define x first
#define y second

int n, k, a[MAXN], len[MAXN], dp[MAXN][MAXN];
int main()
{
    cin >> n >> k;
    FOR(i, n)
    {
        cin >> a[i];
    }
    sort(a, a+n);
    FOR(i, n)
    {
        int j = i;
        while(j < n && a[j] - a[i] <= 5)
        {
            j++;
            len[i]++;
        }
    }
    FOR(i, n)
    {
        FOR(j, k+1)
        {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]); // continue this team
            if(j+1<=k)
            {
                // add another team
                dp[i+len[i]][j+1] = max(dp[i+len[i]][j+1], dp[i][j] + len[i]);
            }
        }
    }
    cout << dp[n][k] << endl;
}