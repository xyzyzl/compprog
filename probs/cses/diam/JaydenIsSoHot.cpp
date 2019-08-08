#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> adj_lst[200005], v;
int dfs(int k, int par)
{
    int mx = 0;
    for(int j : adj_lst[k])
    {
        if(j != par) mx = max(mx, 1+dfs(j, k));
    }
    return mx;
}
void d()
{
    int m = 0;
    int ct = 0;
    if(n > 2) while(adj_lst[m].size() <= 2 && ct < n)
    {
        m = adj_lst[m][0];
        ct++;
    }
    for(int p : adj_lst[m])
    {
        v.push_back(1+dfs(p, m));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    cout << (v[0] + v[1]) << endl;
}
int main()
{
    cin >> n;
    if(n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj_lst[a].push_back(b);
        adj_lst[b].push_back(a);
    }
    d();
}