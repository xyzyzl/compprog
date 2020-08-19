#include <bits/stdc++.h>
using namespace std;

int n, m;
int mp[26];
string s[1005];
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int b = 0;
    for(int i = 0; i < m; i++)
    {
        int mult;
        cin >> mult;
        fill(mp, mp+26, 0);
        for(int j = 0; j < n; j++)
        {
            mp[s[j][i] - 'A']++;
        }
        int mx = 0;
        for(int j = 0; j < 26; j++)
            mx = max(mx, mp[j]);
        b += mx*mult;
    }
    cout << b << endl;
}