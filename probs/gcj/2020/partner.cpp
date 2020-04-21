// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1000005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define F1R(i, n) for (int i = 1; i <= n; i++)
#define F1RD(i, n) for (int i = n; i >= 1; i--)
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
#define MOD (1e9*1)+7
#define MOD2 998244353
#define INF (1e9*1)+5

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

void solve(int tc)
{
    cout << "Case #" << tc << ": ";
	int n;
    cin >> n;
    vector<bool> ans(n);
    viii events;
    si cur;
    FOR(i, n)
    {
        int a, b;
        cin >> a >> b;
        events.pb(mp(a, mp(1, i)));
        events.pb(mp(b, mp(-1, i)));
    }
    sort(events.begin(), events.end());
    for(iii x : events)
    {
        if(cur.size() == 1 && x.s.f == 1)
        {
            ans[x.s.s] = !ans[*cur.begin()];
        } else if(cur.size() > 2)
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        if(cur.count(x.s.s))
        {
            cur.erase(x.s.s);
        } else cur.insert(x.s.s);
    }
    FOR(i, n)
    {
        cout << (ans[i] ? 'J' : 'C');
    }
    cout << endl;
}

int main()
{
	int t = 1;
	cin >> t; // uncomment if it's multitest
	int tc = 0;
    while(t--)
	{
        ++tc;
		solve(tc);
	}
	
}
