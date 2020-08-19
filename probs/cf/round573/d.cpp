#include <bits/stdc++.h>

#define int long long

using namespace std;
#define MAXN 100005

int n, a[MAXN];
signed main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n==1)
    {
        cout << (a[0] % 2 ? "sjfnb" : "cslnb");
    }
    else
    {
        int sum = 0;
        for(int i = 0; i < n; i++) sum += a[i];
        if(sum == 0) cout << "cslnb";
        else cout << (sum % 2 ? "cslnb" : "sjfnb");
    }
    
}