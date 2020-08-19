#include <bits/stdc++.h>

using namespace std;

int n;
int deg[100005];
int main()
{
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(deg[i] == 2)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}