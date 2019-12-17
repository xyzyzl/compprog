// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1000005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
#define FOBIRD(i, n) for (int i = n; i >= 1; i--)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL)

#define fileio(in, out)      \
    freopen(in, "r", stdin); \
    freopen(out, "w", stdout);

#define ll long long

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> iii;
typedef vector<pii> vii;
typedef vector<iii> viii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

#define LEFT(x) 2 * x
#define RIGHT(x) 2 * x + 1

#define bitinc(x) x&-x

const int MAX(int &a, int b)
{
    return a = max(a, b); 
}
const int MIN(int &a, int b)
{
    return a = min(a, b); 
}

int main()
{
    DUEHOANG;
    int t = 1;
    cin >> t; // uncomment if it's multitest
    while(t--)
    {
        int r,c;
        cin >> r >> c;
        int mat[r][c];
        vi ro(c), co(r);
        memset(mat, 0, sizeof(mat));
        int x = 0;
        FOR(i, r)
        {
            FOR(j, c)
            {
                char c;
                cin >> c;
                mat[i][j] = (c == 'A' ? 1 : 0);
                if(mat[i][j])
                {
                    co[i]++;
                    ro[j]++;
                    x++;
                }
            }
        }
        if(!x)
        {
            cout << "MORTAL" << endl;
            continue;
        }

        int ans = 0;
        if(x == r*c) ans = 0;
        else if(co[0] == c || co[r-1] == c || ro[0] == r || ro[c-1] == r) ans = 1;
        else if(mat[0][0] || mat[r-1][c-1] || mat[0][c-1] || mat[r-1][0]) ans = 2;
        else
        {
            int ko = 0;
            FOR(i, c) MAX(ko, (ro[i] == r));
            FOR(i, r) MAX(ko, (co[i] == c));
            int ok = 0;
            FOR(i, r) MAX(ok, (mat[i][c-1] || mat[i][0]));
            FOR(i, c) MAX(ok, (mat[r-1][i] || mat[0][i]));
            if(ko) ans = 2;
            else if(ok) ans = 3;
            else ans = 4;
        }
        cout << ans << endl;
        continue;
    }
}