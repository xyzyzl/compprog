#include <bits/stdc++.h>
using namespace std;
int a, b;
int dp[505][505];
int main()
{
    cin >> a >> b;
    for(int i = 1; i <= a; i++) for(int j = 1; j <= b; j++) dp[i][j] = (int)(1e9*2+7);
    for(int i = 1; i <= a; i++) for(int j = 1; j <= b; j++)
    {
        if(i==j)
        {
            dp[i][j] = 0;
            continue;
        }
        for(int k = 1; k < i; k++) dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
        for(int k = 1; k < j; k++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
    }
    cout << dp[a][b];
}