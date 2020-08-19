#include <bits/stdc++.h>

#define int long long

using namespace std;

#define MAXN 100005

int n, p[MAXN], v[MAXN], a[MAXN];
vector<int> adj[MAXN];

void dfs(int x, int d)
{
    if(x == 0) a[x] = v[x];
    else if(d%2)
    {
        a[x] = v[x] - v[p[x]];
    } else 
    {
        if(adj[x].empty())
        {
            a[x] = 0;
            return;
        }
        int q = v[p[x]];
        int mn = INT_MAX;
        for(int i : adj[x]) mn = min(mn, v[i]);
        mn -= q;
        a[x] = mn;
        v[x] = v[p[x]] + a[x];
    }
    for(int i : adj[x]) dfs(i, d+1);
}

signed main()
{
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
        adj[p[i]].push_back(i);
    }
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++)
    {
        if(v[i] != -1 && v[i] < v[p[p[i]]])
        {
            cout << -1;
            return 0;
        }
    }
    dfs(0, 1);
    int an = 0;
    // for(int i = 0; i < n; i++) cout << a[i] << endl;
    for(int i = 0; i < n; i++) an += a[i];
    cout << an;
}