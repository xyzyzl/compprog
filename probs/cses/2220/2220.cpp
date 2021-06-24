#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll a, b, p9[19];

ll solve(ll x)
{
    if(x == 0) return 1;
    ll ans = 0;
    vector<int> v;
    while(x > 0)
    {
        v.push_back(x%10);
        x/=10;
    }
    // add all previous digits, because those are guaranteed to work.
    for(int i = 0; i < v.size()-1; i++)
    {
        ans += p9[i];
    }
    v.push_back(10);
    for(int i = v.size()-2; i >= 0; i--)
    {
        ans += p9[i]*v[i];
        if(v[i] > v[i+1]) ans -= p9[i]; // there must be a conflict
        if(v[i] ==v[i+1]) return ans; // there is nothing more to do here, because the digits are literally equal.
    }
    return ans+1;
}

int main()
{
    cin >> a >> b;
    p9[0] = 1;
    for(int i = 1; i < 19; i++) p9[i] = p9[i-1]*9ll;
    if(!a) cout << solve(b) << endl;
    else cout << solve(b)-solve(a-1) << endl;
}