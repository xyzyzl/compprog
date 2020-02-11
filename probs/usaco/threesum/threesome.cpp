// Time:
// Algorithms:

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 5005
#define HASHY 2000005

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
#define int ll
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

int n;
ll h_table[HASHY];
ll arr[MAXN];
ll dat[MAXN][MAXN];
bool vis[MAXN][MAXN];

ll asdf(int st, int en)
{
    if (st > en)
        return -1;
    if (st == en)
    {
        // cout << dat[st][en] << endl;
        return dat[st][en];
    }
    if (vis[st][en])
        return dat[st][en];
    vis[st][en] = 1;
    ll first = asdf(st + 1, en);
    ll second = asdf(st, en - 1);
    ll over = asdf(st + 1, en - 1);
    if (first == -1 || second == -1 || over == -1)
        return 0;
    dat[st][en] = dat[st][en] + first + second - over;
    // if(st == 1 && en == 4) cout << first << " " << second << " " << over << endl;
    return dat[st][en];
}

signed main()
{
    DUEHOANG;
    fileio("threesum.in", "threesum.out");
    int t = 1;
    cin >> n >> t; // uncomment if it's multitest
    FOR(i, n)
    {
        cin >> arr[i];
    }
    FORD(i, n)
    {
        // unordered_set<ll> x;
        int curr_sum = 1e6 - arr[i];
        FORR(i + 1, j, n)
        {
            if (1e6 - arr[i] - arr[j] >= 0 && 1e6 - arr[i] - arr[j] <= 2 * 1e6)
            {
                dat[i][j] = h_table[(int)1e6 - arr[i] - arr[j]];
                // cout << i << " " << j << endl;
            }
            // cout << i << " " << j << endl;
            h_table[(int)1e6 + arr[j]]++;
        }
        FORR(i + 1, j, n)
        {
            h_table[(int)1e6 + arr[j]]--;
        }
    }
    // cout << dat[1][4] << endl;
    /*
    FORD(i, n)
    {
	FORR(i+1, j, n)
	{
	    dat[i][j] += dat[i+1][j] + dat[i][j-1] - dat[i+1][j-1];
	}
    }
    */
    asdf(0, n - 1);
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << dat[l][r] << endl;
    }
}
