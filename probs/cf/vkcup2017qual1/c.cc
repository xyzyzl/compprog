#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
 
using namespace std;
 
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char a[4] = {'D', 'L', 'R', 'U'};
 
int n,m,k;
bool vis[1005][1005];
int dist[1005][1005];
int v[1005][1005];
 
bool lmao(int i, int j)
{
    return (0 <= i && i < n && 0 <= j && j < m);
}
 
void calc_dist(int i, int j, int d)
{
    if(!lmao(i,j) || !v[i][j]) return;
    vis[i][j] = 1;
    if(d < dist[i][j])
    {
        dist[i][j] = d;
    }
    else return;
    for(int p = 0; p < 4; p++)
    {
        calc_dist(i+dx[p],j+dy[p],d+1);
    }
}

void bfs(int i, int j)
{
    queue<pair<int, int> > q;
    dist[i][j] = 0;
    q.push(make_pair(i,j));
    while(!q.empty())
    {
        pair<int, int> t = q.front();
        int a = dist[t.first][t.second];
        q.pop();
        if(t.first+1<n && dist[t.first+1][t.second]==INT_MAX)
            q.push({t.first+1,t.second}),dist[t.first+1][t.second]=a+1;
        if(t.second>0 && dist[t.first][t.second-1]==INT_MAX)
            q.push({t.first,t.second-1}),dist[t.first][t.second-1]=a+1;
        if(t.second+1<m && dist[t.first][t.second+1]==INT_MAX)
            q.push({t.first,t.second+1}),dist[t.first][t.second+1]=a+1;
        if(t.first>0 && dist[t.first-1][t.second]==INT_MAX)
            q.push({t.first-1,t.second}),dist[t.first-1][t.second]=a+1;
    }
}
 
string ret = "";
 
int sx,sy;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    if(k%2==1)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
    {
        char c;
        cin >> c;
        if(c == '.') v[i][j] = 1;
        else if(c == 'X')
        {
            v[i][j] = 2;
            sx=i;
            sy=j;
        }
        else v[i][j] = 0;
    }
    // calculate distances
    
    for(int i = 0; i < 1000; i++) for(int j = 0; j < 1000; j++)
    {
        dist[i][j] = INT_MAX;
    }
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(v[i][j] == 0) dist[i][j] = -1;
 
    // cout << "w" << endl;
    
    // cout << sx << " " << sy << endl;
    bfs(sx,sy);
 
    /*
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    */
    
    // find cycle
 
    int i = sx, j = sy;
    for(int r = k; r > 0; r--)
    {
        bool w = 0;
        for(int p = 0; p < 4; p++)
        {
            if(lmao(i+dx[p], j+dy[p]) && dist[i+dx[p]][j+dy[p]] != -1 && dist[i+dx[p]][j+dy[p]] <= r)
            {
                w=1;
                ret += a[p];
                i = i+dx[p];
                j = j+dy[p];
                break; // you don't want to have multiple circuits
            }
        }
        if(!w)
        {
            cout << "IMPOSSIBLE" << endl;
            exit(0);
        }
    }
    cout << ret << endl;
}