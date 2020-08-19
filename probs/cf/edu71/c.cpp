#include <bits/stdc++.h>

#define int long long

using namespace std;

int n, a, b;
signed main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> a >> b;
        vector<vector<int> > dp(n+1);
        for(int i = 0; i <= n; i++)
        {
            dp[i].push_back(0);
            dp[i].push_back(0);
        }
        string s;
        string c;
        cin >> c;
        s = c + "w";
        dp[0][0] = b;
        dp[0][1] = 1e14+7;
        for(int i = 1; i <= n; i++)
        {
            if(s[i] == '1' || s[i-1] == '1')
            {
                dp[i][0] = 1e14 + 7;
                dp[i][1] = min(dp[i-1][1] + 2*b + a, dp[i-1][0] + 2*b + 2*a);
                // cout << dp[i-1][0] << " ";
                continue;
            }

            dp[i][0] = min(dp[i-1][0] + b + a, dp[i-1][1] + b + 2*a);
            dp[i][1] = min(dp[i-1][1] + b*2 + a, dp[i-1][0] + b*2 + 2*a);
        }
        cout << dp[n][0] << endl;
    }
}