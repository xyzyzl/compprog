#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 200005

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

#define fileio(in, out)      \
    freopen(in, "r", stdin); \
    freopen(out, "w", stdout);

#define ll long long

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

int m, n, k, t, ag[MAXN], l[MAXN], r[MAXN], d[MAXN];
int p[MAXN];

int findSet(int i)
{
    return (p[i] == i) ? i : (p[i] = findSet(p[i]));
}
bool isSameSet(int i, int j)
{
    return findSet(i) == findSet(j);
}
void unionSet(int i, int j)
{
    if (!isSameSet(i, j))
    {
        int a = findSet(i), b = findSet(j);
        if (a > b)
        {
            swap(a, b);
        }
        p[a] = b;
    }
}

bool good(int x)
{
    FOBIR(i, n + 1)
    {
        p[i] = i;
    }
    ll asdf = n; // moving m steps in the end
    FOBIR(i, k)
    {
        if (x < d[i])
        {
            int cur = findSet(l[i]);
            while (cur <= r[i])
            {
                unionSet(cur, cur + 1);
                asdf += 2;
                cur = findSet(cur + 1);
            }
        }
    }
    return asdf < t;
}

int main()
{
    DUEHOANG;
    cin >> m >> n >> k >> t;
    FOBIR(i, m)
        cin >> ag[i];
    FOBIR(i, k)
        cin >> l[i] >> r[i] >> d[i];
    sort(ag + 1, ag + m + 1);
    reverse(ag + 1, ag + m + 1);
    int lo = 1, hi = m;
    while (lo <= hi)
    {
        // cout << lo << " " << hi << endl;
        int mid = (lo + hi) / 2;
        if (good(ag[mid]))
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    // cout << good(4) << endl;
    cout << lo - 1 << endl;
}
