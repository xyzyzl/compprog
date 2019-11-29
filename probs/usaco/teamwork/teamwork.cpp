#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 10005

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

int n, k, a[MAXN], dp[MAXN];
int main()
{
    fileio("teamwork.in", "teamwork.out");
    DUEHOANG;
    cin >> n >> k;
    FOR(i, n) cin >> a[i];

    dp[0] = a[0];
    FOR(i, n)
    {
        int cur_max = a[i];
        for(int pre = i; pre >= 0 && i-pre+1 <= k; pre--)
        {
            cur_max = max(cur_max, a[pre]); // added to team.
            if(pre == 0) dp[i] = max(dp[i], cur_max * (i-pre+1));
            else dp[i] = max(dp[i], dp[pre-1] + cur_max * (i-pre+1));
        }
    }
    cout << dp[n-1] << endl;
}