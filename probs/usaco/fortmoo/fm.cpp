#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 205

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL);                \
	cout.tie(NULL)

#define JaydenXia(in, out) \
	freopen(in, "r", stdin); \
	freopen(out, "w", stdout);

#define long long long

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

int n,m,psum[MAXN][MAXN];
int dc(int i, int j, int p, int q)
{
    return psum[p+1][q+1] - psum[i][q+1] - psum[p+1][j] + psum[i][j];
}
int main()
{
    JaydenXia("fortmoo.in", "fortmoo.out");
    DUEHOANG;
    cin >> n >> m;
    FOR(i, n)
    {
        FOR(j, m)
        {
            char c;
            cin >> c;
            psum[i+1][j+1] = psum[i][j+1] + psum[i+1][j] - psum[i][j];
            if(c == 'X') psum[i+1][j+1]++;
        }
    }
    // FOBIR(i, n)
    // {
    //     FOBIR(j, m)
    //     {
    //         cout << psum[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    long ans = 0;
    FOR(r1, n)
    {
        FORR(r1, r2, n)
        {
            int last = -1;
            FOR(i, m)
            {
                bool good = !dc(i, r1, i, r2);
                if(good) ans = max(ans, (long)(r2-r1+1));
                if(good && last != -1) ans = max(ans, (long)(i-last+1) * (long)(r2-r1+1));
                if(dc(i, r1, i, r1) || dc(i, r2, i, r2)) last = -1; // this coordinate won't work
                // because it has hit a swamp place
                if(good && last == -1) last = i; // if it works then we're good!
            }
        }
    }
    cout << ans << endl;
}