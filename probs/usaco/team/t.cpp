#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000009

int n, m, k;
unsigned int dp[2019][15][15];
pair<int, int> arr[2019];

int main()
{
    cin >> n >> m >> k;
    int sz = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = 1;
        sz++;
    }
    for(int i = 0; i < m; i++)
    {
        cin >> arr[i+n].first;
        arr[i+n].second = 0;
        sz++;
    }
    sort(arr, arr+sz);

    for(int i = 0; i <= k; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            dp[sz][i][j] = 0;
        }
    }
    dp[sz][0][0] = 1;
    // cout << sz << endl;
    for(int p = sz-1; p >= 0; p--)
        for(int i = 0; i <= k; i++)
        {
            for(int j = 0; j <= k; j++)
            {
                if(j > i) dp[p][i][j] = 0;
                else
                {
                    if(arr[p].second)
                    {
                        // cow belongs to FJ
                        dp[p][i][j] = (dp[p+1][i][j] + (i > 0 ? dp[p+1][i-1][j] : 0)) % MOD; // add another cow to the set
                    } else 
                    {
                        // cow is a slave to an evil corporation
                        dp[p][i][j] = (dp[p+1][i][j] + (j > 0 ? dp[p+1][i][j-1] : 0)) % MOD; // add another evil cow to the set 
                    }
                }
            }
        }
    cout << dp[0][k][k] << endl;
}