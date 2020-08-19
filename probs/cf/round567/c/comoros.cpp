// I want to be the president of Comoros
#include <bits/stdc++.h>
 
using namespace std;

#define MAXN 1005

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
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

struct flag
{
    int x, y, l;
    int c1, c2, c3;
    flag(int _x, int _y, int _l, int _c1, int _c2, int _c3)
    {
        x = _x;
        y = _y;
        l = _l;
        c1 = _c1;
        c2 = _c2;
        c3 = _c3;
    }
};

int n, m, b[MAXN][MAXN], c[MAXN];
char a[MAXN][MAXN];
int main()
{
    cin >> n >> m;
    FOR(i, n)
    {
        FOR(j, m)
        {
            cin >> a[i][j];
        }
        b[i][0] = 1;
        FOBIR(j, m-1)
        {
            b[i][j] = (a[i][j] == a[i][j-1] ? b[i][j-1]+1 : 1);
        }
    }
    
    long long ans = 0;
    deque<pii> d;
    FOR(j, m)
    {
        d.clear();
        c[0] = 1;
        d.pb(mp(b[0][j], 0));
        FOBIR(i, n-1)
        {
            c[i] = (a[i][j] == a[i-1][j] ? c[i-1] + 1 : 1);
            while(!d.empty() && d.back().f >= b[i][j])
            {
                d.pop_back();
            }
            d.pb(mp(b[i][j], i));
            if(i >= 2*c[i] && c[i] == c[i-c[i]] && c[i] <= c[i-2*c[i]])
            {
                while(d.front().s < i-3*c[i]+1)
                {
                    d.pop_front();
                }
                ans += d.front().f;
            }
        }
    }
    cout << ans << endl;
}