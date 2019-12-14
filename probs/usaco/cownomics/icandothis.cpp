#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 505

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
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

#define LEFT(x) 2 * x
#define RIGHT(x) 2 * x + 1

#define MOD 998252513

#define bitinc(x) x & -x

const int MAX(int &a, int b)
{
    a = max(a, b);
}
const int MIN(int &a, int b)
{
    a = min(a, b);
}

int n, m, S[MAXN][MAXN], P[MAXN][MAXN], H[MAXN], h1[MAXN], h2[MAXN];

int val(char c)
{
    if (c == 'A')
        return 1;
    else if (c == 'C')
        return 2;
    else if (c == 'G')
        return 3;
    else
        return 4;
}

int main()
{
    fileio("cownomics.in", "cownomics.out");
    cin >> n >> m;
    FOR(i, n)
    FOR(j, m)
    {
        char c;
        cin >> c;
        S[i][j] = val(c);
    }
    FOR(i, n)
    FOR(j, m)
    {
        char c;
        cin >> c;
        P[i][j] = val(c);
    }

    FOR(i, m)
    {
        H[i] = rand() % 100402093;
    }
    int lo = 0, hi = 0, mn = m, bad = n;
    while(hi < m)
    {
        int len = hi-lo;
        if(!bad) mn = min(mn, len);

        if(bad)
        {
            bad = 0;
            si st;
            // r * characters from i to j = r * characters 
            FOR(i, n)
            {
                st.insert(h1[i] += H[hi]*S[i][hi]);
            }
            FOR(i, n)
            {
                if(st.count(h2[i] += H[hi]*P[i][hi]))
                {
                    bad++;
                }
            }
            hi++;
        } else
        {
            bad = 0;
            si st;
            // r * characters from i to j = r * characters 
            FOR(i, n)
            {
                st.insert(h1[i] -= H[lo]*S[i][lo]);
            }
            FOR(i, n)
            {
                if(st.count(h2[i] -= H[lo]*P[i][lo]))
                {
                    bad++;
                }
            }
            lo++;
        }
    }
    cout << mn << endl;
}