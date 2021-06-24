#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20;

int N, K, A[MAXN][MAXN], dp[MAXN][MAXN], ans, c[MAXN][MAXN];
// dp[i][j] = answer w/ first i rows, j fences already installed
// c[i][j] = number of cows between cols i, j assuming that we have walls as defined by some bitmask
int main()
{
    freopen("partition.in", "r", stdin);
    freopen("partition.out", "w", stdout);
    cin >> N >> K;
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
    {
        cin >> A[i][j];
    }
    ans = INT_MAX;
    // brute force over which horizontal walls to include
    for(int msk = 0; msk < (1 << (N-1)); msk++)
    {
        // set every 1 in msk to a wall at index i, horizontally
        if(__builtin_popcount(msk) > K) continue;
        for(int i = 0; i < N; i++)
        {
            vector<int> v(N);
            for(int j = i+1; j <= N; j++)
            {
                // finding costs for range [i, j]
                c[i][j] = 0;
                int sm = 0;
                // for all rows up to each boundary
                for(int ro = 0; ro < N; ro++)
                {
                    v[ro] += A[j-1][ro];
                    sm += v[ro];
                    c[i][j] = max(c[i][j], sm);
                    if((msk >> ro) & 1) sm = 0; // reached a bound
                }
            }
        }
        int x = __builtin_popcount(msk);
        for(int i = 0; i <= N; i++) for(int j = 0; j <= N; j++)
        {
            dp[i][j] = INT_MAX;
        }
        dp[0][0] = 0;
        for(int j = 1; j <= min(N, K-x+1); j++)
        {
            for(int i1 = 0; i1 < N; i1++) for(int i2 = i1+1; i2 <= N; i2++)
            {
                dp[i2][j] = min(dp[i2][j], max(dp[i1][j-1], c[i1][i2]));
            }
            ans = min(ans, dp[N][j]);
        }
    }
    cout << ans << endl;
}