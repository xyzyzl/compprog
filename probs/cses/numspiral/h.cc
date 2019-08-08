#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n;
ll f(ll x)
{
    return 1+x*(x+1);
}
ll g(ll x)
{
    return x%2 ? -1 : 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    cin >> n;
    for(ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        ll p = min(a, b), q = max(a, b);
        p--; q--;
        if(b > a) cout << (f(q)+g(q)*(q-p)) << endl;
        else if(b==a) cout << (f(q)) << endl;
        else cout << (f(q)-g(q)*(q-p)) << endl;
    }
}