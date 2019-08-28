#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
 
using namespace std;
 
#define MAXN 201
 
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORD(i, n) for(int i = n-1; i >= 0; i--)
#define FOBIR(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG ios_base::sync_with_stdio(0); cin.tie(); cout.tie()
 
typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define x first
#define y second

bool vis[1005][1005];
pii p[3];
bool b(pii a, pii b)
{
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}
int main()
{
    DUEHOANG;
    cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y >> p[2].x >> p[2].y;
    sort(p, p+3);
    int mx = p[1].x;
    int dx = p[2].x - p[0].x;
    sort(p, p+3, b);
    int my = p[1].y;
    int dy = p[2].y - p[0].y;
    cout << dx + dy + 1 << endl;

    FOR(i, 3)
    {
        // cout << vis[p[i].x][p[i].y] << endl;
        if(p[i].x < mx)
            for(int j = p[i].x; j <= mx; j++)
            {
                if(!vis[j][p[i].y])
                {
                    cout << j << " " << p[i].y << endl;
                    vis[j][p[i].y] = 1;
                }
                // cout << "askar" << endl;
            }
        else
            for(int j = p[i].x; j >= mx; j--)
            {
                if(!vis[j][p[i].y])
                {
                    cout << j << " " << p[i].y << endl;
                    vis[j][p[i].y] = 1;
                }
                // cout << j << endl;
            }
        if(p[i].y < my)
            for(int j = p[i].y + 1; j <= my; j++)
            {
                if(!vis[mx][j])
                {
                    cout << mx << " " << j << endl;
                    vis[mx][j] = 1;
                }
            }
        else
            for(int j = p[i].y - 1; j >= my; j--)
            {
                if(!vis[mx][j])
                {
                    cout << mx << " " << j << endl;
                    vis[mx][j] = 1;
                }
            }
    }
}