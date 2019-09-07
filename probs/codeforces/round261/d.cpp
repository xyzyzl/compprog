#include <bits/stdc++.h>

using namespace std;

int bit[1000005];

void add(int x, int v)
{
    x++;
    while(x < 1000005)
    {
        bit[x] += v;
        x+=(x&-x);
    }
}

int get(int x)
{
    int ret = 0;
    while(x > 0)
    {
        ret += bit[x];
        x -= x&-x;
    }
    return ret;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n), b;
    for(int i = 0; i < n; i++) cin >> a[i], b.push_back(a[i]);
    // cout << "w" << endl;
    sort(b.begin(), b.end());
    unique(b.begin(), b.end());
    for(int i = 0; i < n; i++)
    {
        a[i] = lower_bound(b.begin(), b.end(), a[i])-b.begin();
    }
    // cout << "gurbanguly" << endl;
    vector<int> v(n), r(n);
    fill(v.begin(), v.end(), 0);
    for(int i = n-1; i >= 0; i--)
    {
        v[a[i]]++;
        add(v[a[i]], 1);
        r[i] = v[a[i]];
    }
    // cout << "berdimuhamedow" << endl;
    long long ans = 0;
    fill(v.begin(), v.end(), 0);
    for(int i = 0; i < n; i++)
    {
        add(r[i], -1);
        v[a[i]]++;
        ans += get(v[a[i]]) - get(1);
    }
    cout << ans << endl;
}