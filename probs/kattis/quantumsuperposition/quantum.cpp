#include <bits/stdc++.h>

using namespace std;

int n, n1, n2, m1, m2, indeg[100005];
set<int> dp[2][100005];
vector<int> adj[100005], res;

bool topo()
{
    multiset<int> st;
    for(int i = 0; i < n; i++)
    {
        if(!indeg[i]) st.insert(i);
    }
    for(int i = 0; i < n; i++)
    {
        int u = *st.begin();
        if(st.empty()) return 0;
        st.erase(st.begin());
        res.push_back(u);
        for(int v : adj[u])
        {
            if(--indeg[v] == 0) st.insert(v);
        }
    }
    return 1;
}

int main()
{
    cin >> n1 >> n2 >> m1 >> m2;
    for(int i = 0; i < m1; i++)
    {
        int u,v;
        cin >> u >> v;
        --u; --v;
        adj[v].push_back(u);
        indeg[u]++;
    }
    n = n1;
    topo();
    reverse(res.begin(), res.end());
    for(int i = 0; i < n; i++)
    {
        if(adj[i].empty()) dp[0][i].insert(0);
    }
    for(int u : res) for(int v : adj[u]) for(int k : dp[0][v]) dp[0][u].insert(1+k);
    for(int i = 0; i < n; i++)
    {
        adj[i].clear();
        indeg[i] = 0;
    }
    res.clear();
    for(int i = 0; i < m2; i++)
    {
        int u,v;
        cin >> u >> v;
        --u; --v;
        adj[v].push_back(u);
        indeg[u]++;
    }
    n = n2;
    topo();
    reverse(res.begin(), res.end());
    for(int i = 0; i < n; i++)
    {
        if(adj[i].empty()) dp[1][i].insert(0);
    }
    for(int u : res) for(int v : adj[u]) for(int k : dp[1][v]) dp[1][u].insert(1+k);
    int q;
    cin >> q;
    while(q--)
    {
        int x;
        cin >> x;
        bool ok = 0;
        for(int k : dp[0][n1-1])
        {
            if(dp[1][n2-1].count(x-k)) 
            {
                ok = 1;
            }
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
}