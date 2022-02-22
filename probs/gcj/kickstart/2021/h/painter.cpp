#include <bits/stdc++.h>

using namespace std;

map<char, int> vals;

int f(int c, int n, vector<int>& v)
{
    int nc = 0;
    for(int i = 1; i <= n; i++)
    {
        // cerr << ((v[i-1] & (1 << c)) == 0) << " " << (v[i] & (1 << c)) << endl;
        if(((v[i-1] & (1 << c)) == 0) && (v[i] & (1 << c)))
        {
            ++nc;
        }
    }
    return nc;
}

int solve()
{
    int n; cin >> n;
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++)
    {
        char c; cin >> c;
        v[i] = vals[c];
    }
    return f(0,n,v) + f(1,n,v) + f(2,n,v);
}

int main()
{
    vals['U'] = 0;
    vals['R'] = 1;
    vals['Y'] = 2;
    vals['O'] = 3;
    vals['B'] = 4;
    vals['P'] = 5;
    vals['G'] = 6;
    vals['A'] = 7;
    int t; cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}