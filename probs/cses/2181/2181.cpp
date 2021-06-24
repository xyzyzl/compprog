#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

int n, m, dp[1005][(1 << 10)+1];

// 0 in the mask means horizontal, 1 in the mask means vertical
void solve(int i, int j, int mc, int mn)
{
    if(i == m) return;
    if(j >= n) // figured out all points
    {
        dp[i+1][mn] = (dp[i+1][mn] + dp[i][mc])%MOD;
    } else 
    {
        if(mc & (1 << j)) solve(i, j+1, mc, mn); // must have another tail for each vertical
        else 
        {
            solve(i, j+1, mc, mn | (1 << j)); // make a new vertical
            if(j+1 < n && !(mc & (1 << (j+1)))) solve(i, j+2, mc, mn); // do not include a vertical, make a horizontal.
        }
    }
}

int main()
{
    cin >> n >> m;
    dp[0][0] = 1;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < (1 << n); j++)
        {
            // start here
            solve(i, 0, j, 0);
        }
    }
    cout << dp[m][0] << endl;
}