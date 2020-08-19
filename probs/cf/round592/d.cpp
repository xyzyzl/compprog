#include <bits/stdc++.h>

using namespace std;

int n, deg[100005];
int c[3][100005];
vector<int> adj[100005];
int dp[100005];

int dfs(int v, int l)
{
    int mn = INT_MAX;
    for(int i : adj[v])
    {
        for(int a = 1; a <= 3; a++)
        {
            if(a == l) continue;
            mn = min(mn, dfs(i,a));
        }
    }
    return mn;
}

int main()
{
    cin >> n;
    for(int j = 0; j < 3; j++)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> c[j][i];
        }
    }
    for(int i = 0; i < n-1; i++)
    {
        int a,b;
        cin>> a >> b;
        adj[a].push_back(b);
        deg[a]++; deg[b]++;
        if(deg[a] >= 3 || deg[b] >= 3)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    
}