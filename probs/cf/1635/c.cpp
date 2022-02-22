#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(a[n-2] > a[n-1]) 
    {
        cout << -1 << endl;
        return;
    }
    if(a[n-1] < 0)
    {
        for(int i = 0; i < n-1; i++)
        {
            if(a[i] > a[i+1])
            {
                cout << -1 << endl;
                return;
            }
        }
        cout << 0 << endl;
        return;
    }
    cout << n-2 << endl;
    for(int i = 0; i < n-2; i++)
    {
        cout << i+1 << " " << n-1 << " " << n << endl;
    }
}

int main()
{
    int t; cin >> t;
    while(t--) solve();
}