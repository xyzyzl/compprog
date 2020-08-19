#include <bits/stdc++.h>

using namespace std;

int n, k, a[300005], b[300005];
int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int be = -a[0] + a[n-1];
    for(int i = 0; i < n-1; i++)
    {
        b[i] = a[i] - a[i+1];
    }
    sort(b, b+n-1);
    for(int i = 0; i < k - 1; i++)
    {
        be += b[i];
    }
    cout << be << endl;
}