#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;
    vector<int> a(n+2);
    vector<int> b(n+2);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    a[0] = a[n+1] = 1e9;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] > a[i+1] && a[i] > a[i-1])
        {
            a[i+1] = max(a[i], a[i+2]);
        }
    }
    int ans =0 ;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] != b[i]) 
        ans++;
    }
    cout << ans << endl;
    for(int i = 1; i <= n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}

int main()
{
    int t; cin >> t;
    while(t--) solve();
}