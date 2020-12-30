#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 200005

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
// ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;
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

bool cmp(iii a, iii b)
{
	if(a.s.f+a.s.s == b.s.f+b.s.s) return a.f < b.f;
	return a.s.f+a.s.s < b.s.f+b.s.s;
}

void solve()
{
	int n, k; cin >> n >> k;
	string s; cin >> s;
	int ans = 0;
	FOR(i, n) if(s[i] == 'W') ans += ((i > 0 && s[i-1] == 'W') ? 2 : 1);
	viii l;
	FOR(i, n)
	{
		if(s[i] == 'L')
		{
			if(i == 0)
			{
				l.pb(mp(1, mp(1, (i == n-1))));
			}
			else if(i > 0 && s[i-1] == 'L')
			{
				l.back().f++;
				if(i == n-1) l.back().s.s = 1;
			}
			else l.pb(mp(1, mp(0, (i == n-1))));
		}
	}
	// cerr << ans << endl;
	sort(l.begin(), l.end(), cmp);
	for(iii i : l)
	{
		if(k >= i.f)
		{
			k -= i.f;
			ans += i.f*2 - i.s.f - i.s.s + 1;
		} else if(k > 0)
		{
			ans += k*2 - min(i.s.f, i.s.s);
			k = 0;
		}
	}
	cout << ans << endl;
}

signed main()
{
	DUEHOANG;
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
