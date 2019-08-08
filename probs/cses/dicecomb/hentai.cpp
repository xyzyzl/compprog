#include <iostream>

using namespace std;

#define MAXN 1000005
#define MOD (int)(1e9+7)

int64_t n, dp[MAXN];
int main()
{
    cin >> n;
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(i-1 >= 0) dp[i]+=dp[i-1];
        if(i-2 >= 0) dp[i]+=dp[i-2];
        if(i-3 >= 0) dp[i]+=dp[i-3];
        if(i-4 >= 0) dp[i]+=dp[i-4];
        if(i-5 >= 0) dp[i]+=dp[i-5];
        if(i-6 >= 0) dp[i]+=dp[i-6];
        dp[i] %= MOD;
    }
    cout << dp[n] % MOD << endl;
}