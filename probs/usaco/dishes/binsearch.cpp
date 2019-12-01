
#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 100005

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

#define mrduehoang(in, out) \
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
#define f first
#define s second

int n, ord[MAXN], bot[MAXN];
vi v[MAXN];
int main()
{
    mrduehoang("dishes.in", "dishes.out");
    cin >> n;
    int mx = 0;
    FOR(i, n)
    {
        int x;
        cin >> x;
        if(x < mx) 
        {
            cout << i << endl;
            return 0;
        }
        for(int j = x; j > 0; j--)
        {
            if(bot[j]) break;
            else bot[j] = x;
        }
        while(!v[bot[x]].empty() && v[bot[x]].back() < x)
        {
            mx = v[bot[x]].back();
            v[bot[x]].pop_back();
        }
        v[bot[x]].pb(x);
    }
    cout << n << endl;
}