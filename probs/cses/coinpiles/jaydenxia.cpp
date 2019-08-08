// time: 5:30

#include <bits/stdc++.h>

using namespace std;

int t;
int main()
{
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        int m = min(a, b);
        int n = max(a, b);
        if((m+n)%3 || n>2*m) cout << "NO\n";
        else cout << "YES\n";
    }
}