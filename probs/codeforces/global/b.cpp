#include <bits/stdc++.h>

using namespace std;

int n, m, k, a[100005], d[100005];
int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i == 0) continue;
        d[i] = a[i] - a[i-1];
    }
    sort(d, d+n);
    int j = n;
    for(int i = 1; i <= n-k; i++)
    {
        j += d[i]-1;
    }
    cout << j << endl;
}