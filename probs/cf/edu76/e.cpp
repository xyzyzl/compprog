// Time:
// Algorithms:

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 200005

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
#define INF (1e9 * 1) + 5

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

#define bitinc(x) x & -x

const int MAX(int &a, int b)
{
    return a = max(a, b);
}
const int MIN(int &a, int b)
{
    return a = min(a, b);
}

int k[3], a[3][MAXN];

int lis(vi v)
{
    si st;
    set<int>::iterator it;
    st.clear();
    FOR(i, (v.size()))
    {
        st.insert(v[i]);
        it = st.find(v[i]);
        it++;
        if (it != st.end())
            st.erase(it);
    }
    return st.size();
}

int main()
{
    DUEHOANG;
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while (t--)
    {
        FOR(i, 3)
            cin >> k[i];
        FOR(i, k[0])
        {
            cin >> a[0][i];
        }
        FOR(i, k[1])
        {
            cin >> a[1][i];
        }
        FOR(i, k[2])
        {
            cin >> a[2][i];
        }
        // cout << "h" << endl;
        FOR(i, 3)
        sort(a[i], a[i] + k[i]);
        // concatenate the arrays
        vi fin;
        FOR(i, 3)
        FOR(j, k[i]) fin.pb(a[i][j]);
        // find LIS in fin
        int tot = k[0] + k[1] + k[2];
        cout << (tot - lis(fin)) << endl;
    }
}