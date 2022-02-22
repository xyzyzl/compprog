#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for(int i = 0; i < 30; i++) 
    {
        for(int j = 0; j < n; j++)
        {
            if(a[j] & (1 << i))
            {
                ans += (1 << i);
                break;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        solve();
    }
}