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
#define f first
#define s second

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int n, m;
char a[55][55];
int sx, sy;
int main()
{
    cin >> n >> m;
    FOR(i, n) FOR(j, m)
    {
        cin >> a[i][j];
        if(a[i][j] == 'S')
        {
            sx = i;
            sy = j;
        }
    }
    string bishkek;
    cin >> bishkek;
    vector<int> v = { 0, 1, 2, 3 };

    int ans = 0;
    do
    {
        int x = sx, y = sy;
        bool thing = 0;
        FOR(i, bishkek.length())
        {
            int j = bishkek[i]-'0';
            x += dx[v[j]];
            y += dy[v[j]];
            if(x < 0 || y < 0 || x >= n || y >= m) break;
            if(a[x][y] == '#') break;
            if(a[x][y] == 'E')
            {
                thing = 1;
                break;
            }
        }
        ans += thing;
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << endl;
}