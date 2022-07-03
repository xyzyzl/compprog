#include <bits/stdc++.h>

using namespace std;

// fenwick tree to keep track of how many values there are for each frequency.
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
    sort(b.begin(), b.end());
    unique(b.begin(), b.end());
    for(int i = 0; i < n; i++)
    {
        a[i] = lower_bound(b.begin(), b.end(), a[i])-b.begin();
    }
    vector<int> v(n), r(n);
    fill(v.begin(), v.end(), 0);
    for(int i = n-1; i >= 0; i--)
    {
        v[a[i]]++;
        add(v[a[i]], 1);
        r[i] = v[a[i]]; // frequency of indices equal to a[i] to the right of a[i]. we add this to a BIT
    }
    long long ans = 0;
    fill(v.begin(), v.end(), 0);
    for(int i = 0; i < n; i++)
    {
        add(r[i], -1); // we have to remove one with frequency r[i]
        v[a[i]]++; // frequency of a[i] on the left
        ans += get(v[a[i]]) - get(1); // find the number of points j on the right s.t. a[j] appears less frequently to the right of j
        // than a[i] appears to the left of i
    }
    cout << ans << endl;
}