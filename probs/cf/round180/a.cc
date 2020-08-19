#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a,b;
    cin >> a >> b;
    int a1=0,b1=0;
    for(int i = 0; i < a.length(); i++) if(a[i]=='1')a1++;
    for(int i = 0; i < b.length(); i++) if(b[i]=='1')b1++;
    cout << ((a1 >= b1 || (a1+a1%2 >= b1)) ? "YES\n" : "NO\n");
}