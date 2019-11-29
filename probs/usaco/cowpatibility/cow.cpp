#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 50005

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
#define int ll

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

typedef pair<int, vi> sset;

int n;
const int pie[6] = {-1, +1, -1, +1, -1, +1};
vi arr[MAXN];

struct container_hash
{
    int operator()(const vector<int> &V) const
    {
        int hash = 0;
        for (int i = 0; i < V.size(); i++)
        {
            hash += V[i];
        }
        return hash;
    }
};

unordered_map<vi, int, container_hash> r;

vi get_sset(int x, vi full)
{
    vi st;
    for (int i = 0; i < 5; i++)
    {
        if ((1 << i) & x)
            st.push_back(full[i]);
    }
    return st;
}

#undef int
int main()
{
#define int ll
    DUEHOANG;
    fileio("cowpatibility.in", "cowpatibility.out");
    cin >> n;
    FOR(i, n)
    {
        arr[i].resize(5);
        FOR(j, 5)
        {
            cin >> arr[i][j];
        }
        sort(arr[i].begin(), arr[i].end());
        for (int x = 1; x < 32; x++)
            r[get_sset(x, arr[i])]++;
    }

    ll ans = n * (n - 1) / 2;
    for (auto &o : r)
    {
        ans -= pie[o.f.size()] * o.s * (o.s - 1) / 2;
    }
    cout << ans << endl;
}