#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define int long long

int t,n,s,l[200005],r[200005];

// compares two indices based on lower l value
bool comp(int a, int b)
{
    return l[a] < l[b];
}

// check if best median salary
bool good(int mid)
{
    int sum = 0, lower = 0;
    vector<int> idk;
    for(int i = 0; i < n; i++)
    {
        if(r[i] < mid)
        {
            sum += l[i];
            lower++;
        }
        else if(l[i] >= mid)
        {
            sum += l[i];
        }
        else idk.push_back(i);
    }
    /*
    for(int i = 0; i < idk.size(); i++)
    {
        cout << i << " ";
    }
    cout << endl;
    */
    // so now for each index s.t. l < mid < r, find best way.
    sort(idk.begin(), idk.end(), comp);
    int x = min((int)idk.size(), n/2 - lower);
    if(x<0) return false;
    for(int i = 0; i < x; i++)
    {
        sum += l[idk[i]];
    }
    for(int i = x; i < idk.size(); i++)
    {
        sum += mid;
    }
    // cout << sum << " " << mid << endl;
    return sum <= s;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        for(int i = 0; i < n; i++)
        {
            cin >> l[i] >> r[i];
        }
        // bin search for a min
        int lo = 1, hi = s+69;
        while(hi - lo > 1)
        {
            // cout << lo << " " << hi << endl;
            int mid = (lo+hi)/2;
            if(good(mid)) lo = mid;
            else hi = mid-1;
        }
        if(!good(hi)) cout << lo << endl;
        else cout << hi << endl;
    }
}