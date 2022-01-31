#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;
    vector<vector<int> > a(n, vector<int>(n));
    vector<vector<int> > b(n, vector<int>(n));
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
    {
        cin >> a[i][j];
    }
    int ans = 0;
    for(int i = 1; i < n; i++) for(int j = 0; j < n; j++)
    {
        if(!b[i-1][j])
        {
            ans ^= a[i][j];
            b[i-1][j] ^= 1;
            if(j) b[i][j-1] ^= 1;
            if(i < n-1) b[i+1][j] ^= 1;
            if(j < n-1) b[i][j+1] ^= 1;
        }
    }
    cout << ans << endl;
}

int main()
{
    int t; cin >> t;
    while(t--) solve();
}