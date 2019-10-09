#include <bits/stdc++.h>

#define MAXN 300005

using namespace std;

int n, k, dp[MAXN], ts[MAXN]; // n, k, minimum number of majority-guernsey districts,
// #holstein - #guernsey
multiset<int> ac, pa[MAXN]; // each active value, indices for that active value
int main()
{
    freopen("redistricting.in", "r", stdin);
    freopen("redistricting.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        if(c == 'H')
        {
            ts[i] = ts[i-1] + 1;
        } else 
        {
            ts[i] = ts[i-1] - 1;
        }
    }
    ac.insert(0);
    pa[0].insert(0);
    for(int i = 1; i <= n; i++)
    {
        auto w = ac.begin();
        if(*pa[*w].begin() < ts[i]) dp[i] = *w;
        else dp[i] = *w + 1;
        ac.insert(dp[i]);
        pa[dp[i]].insert(ts[i]);
        if(i >= k)
        {
            ac.erase(ac.find(dp[i-k]));
            pa[dp[i-k]].erase(pa[dp[i-k]].find(ts[i-k]));
        }
    }
    cout << dp[n] << endl;
}