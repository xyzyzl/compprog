#include <bits/stdc++.h>

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
    if(!lmao(i,j) || !v[i][j] || vis[i][j]) return;
    vis[i][j] = 1;
    dist[i][j] = d;
    for(int p = 0; p < 4; p++)
    {
        calc_dist(i+dx[p],j+dy[p],d+1);
    }
}

string ret = "";

int sx,sy;

void dfs(int i, int j, int r)
{
    // cout << sx << " " << sy << endl;
    if(r == 0)
    {
        // cout << i << " the " << j << endl;
        
        // cout << ret << endl;
        if((i != sx) || (j != sy))
        {
            // cout << i << " " << sx << " " << j << " " << sy << endl;
            cout << "IMPOSSIBLE" << endl;
            exit(0);
        }
        return;
    }
    bool w = 0;
    for(int p = 0; p < 4; p++)
    {
        if(lmao(i+dx[p], j+dy[p]) && dist[i+dx[p]][j+dy[p]] != -1 && dist[i+dx[p]][j+dy[p]] <= r)
        {
            w=1;
            ret += a[p];
            dfs(i+dx[p], j+dy[p], r-1);
            break; // you don't want to have multiple circuits
        }
    }
    if(!w)
    {
        cout << "IMPOSSIBLE" << endl;
        exit(0);
    }
}

int main()
{
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
        dist[i][j] = -1;
    }

    // cout << "w" << endl;
    
    // cout << sx << " " << sy << endl;
    dist[sx][sy]=0;
    calc_dist(sx,sy,0);

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

    dfs(sx,sy,k);
    cout << ret << endl;
}