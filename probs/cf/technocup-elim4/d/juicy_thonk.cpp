#include <bits/stdc++.h>

#pragma GCC optimize ("O3")

using namespace std;

int n, s, deg[100005];
int main()
{
    cin >> n >> s;
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
    }
    int w = 0;
    for(int i = 1; i <= n; i++)
    {
        if(deg[i] == 1) w++;
    }
    cout << setprecision(10) << fixed << (double)(2.0*s) / (double)(w) << endl;
}