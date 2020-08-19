#include <bits/stdc++.h>
 
using namespace std;
 
long long n, sum, mx;
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        sum += a;
        mx = max(mx, a);
    }
    if(mx > sum/2) cout << "NO";
    else cout << (sum%2 ? "NO" : "YES");
}