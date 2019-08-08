#include <bits/stdc++.h>

#define MAXN 200005

using namespace std;

int n, l=1, a[MAXN], d[MAXN];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    d[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        if(a[i] > d[l-1]) d[l++] = a[i];
        else
        {
            auto t = find(d, d+l, a[i]);
            if(t != d+l) continue;
            t = upper_bound(d, d+l, a[i]);
            *t = a[i];
        }
    }
    cout << l;
}