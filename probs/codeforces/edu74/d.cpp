#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n;
string s;
int main()
{
    cin >> n >> s;
    ll tot = n*(n+1)/2 - n;
    int ind = 0;
    vector<ll> v;
    for(int i = 0; i < n; i++)
    {
        if(s[i] != s[ind])
        {
            v.push_back(i-ind);
            ind = i;
        }
    }
    v.push_back(n-ind);
    
    ll ans=0;
    for(int i = 1; i < v.size(); i++)
    {
        ans += (v[i] + v[i-1] - 1);
    }
    ans = tot-ans;
    cout << ans << endl;
}