#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, k, sum[300005], arr[300005];
signed main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = n-1; i > 0; i--)
    {
        sum[i] = sum[i+1] + arr[i];
    }
    int a = sum[1] + arr[0];
    // cout << a << endl;
    sort(sum+1, sum+n);
    reverse(sum+1, sum+n);
    int ans = a;
    for(int i = 1; i < k; i++)
    {
        ans += sum[i];
    }
    cout << ans << endl;
}