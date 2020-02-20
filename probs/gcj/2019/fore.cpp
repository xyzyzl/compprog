#include <bits/stdc++.h>

using namespace std;

void solve(int t)
{
    string n;
    cin >> n;
    vector<char> v(n.length());
    bool oops = false;
    for(int i = 0; i < n.length(); i++)
    {
        if(n[i] == '4')
        {
            n[i] = '3';
            v[i] = '1';
            oops = true;
        } else 
        {
            if(oops) v[i] = '0';
            else v[i] = 0;
        }
    }
    cout << "Case #" << t << ": ";
    for(char c : n)
    {
        cout << c;
    }
    cout << ' ';
    for(char c : v)
    {
        if(c) cout << c;
    }
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        solve(i);
    }
}