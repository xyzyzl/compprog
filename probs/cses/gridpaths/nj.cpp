// tem: 12:33

#include <bits/stdc++.h>

using namespace std;

int n;
bool g[1005][1005];
int dp[1005][1005];
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            if(c == '.') g[i][j]=1;
            else g[i][j]=0;
        }
    }
    if(!g[0][0])
    {
        cout << 0;
        return 0;
    }
    dp[0][0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(g[i][j] == 0) continue;
            if(i>0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % 1000000007;
            if(j>0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % 1000000007;
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }
    cout << dp[n-1][n-1] << endl;
}