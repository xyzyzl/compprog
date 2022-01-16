#include <bits/stdc++.h>

using namespace std;

int n;
bool work(int k, vector<int>& h, vector<int> &j)
{
    for(int i = 0; i < n-2; i++)
    {
        if(k == 13)
        {
            cout << j[i] << " " << h[i] << " " << k << endl;
        }
        if(h[i] >= k)
        {
            int d = min(j[i],h[i]-k)/3;
            h[i+2] += 2*d;
            h[i+1] += d;
            h[i] -= 3*d;
        } else return 0;
    }
    for(int i = 0; i < n; i++) if(h[i] < k) return 0;
    return 1;
}

void solve()
{
    cin >> n;
    vector<int> h(n), j(n);
    for(int i = 0; i < n; i++)
    {
        cin >> h[i];
        j[i] = h[i];
    }
    reverse(h.begin(), h.end());
    reverse(j.begin(), j.end());
    int lo = 0, hi = *max_element(h.begin(),h.end()) + 1;
    while(lo < hi - 1)
    {
        for(int i = 0; i < n; i++) h[i] = j[i];
        int mid = (lo+hi)/2;
        if(work(mid, h, j))
        {
            lo = mid;
        } else 
        {
            hi = mid;
        }
    }
    cout << lo << endl;
}

int main()
{
    // freopen("c.txt", "r", stdin);
    int t; cin >> t;
    while(t--)
    {
        solve();
    }
}