#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;
const int MOD = 1e9+7;

int n, p;
int a[MAXN], dp[MAXN], f[MAXN];
int main()
{
    cin >> n >> p;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    set<int> v;
    for(int i = 0; i < n; i++)
    {
        int x = a[i];
        bool dumb = 0;
        while(x > 0)
        {
            if(v.count(x))
            {
                dumb = 1;
                break;
            }
            if(x % 2)
            {
                x /= 2;
            } else if(!(x % 4))
            {
                x /= 4;
            } else 
            {
                break;
            }
        }
        if(!dumb) v.insert(a[i]);
    }
    for(int x : v)
    {
        dp[(int)floor(log2(x))]++;
    }
    for(int i = 1; i < p; i++)
    {
        dp[i] = (dp[i] + dp[i-1]) % MOD;
        if(i >= 2) dp[i] = (dp[i] + dp[i-2]) % MOD;
    }
    int ans=0;
    for(int i = 0; i < p; i++)
    {
        ans = (ans+dp[i])%MOD;
    }
    cout << ans << endl;
}