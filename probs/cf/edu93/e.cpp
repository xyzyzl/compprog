// Time:
// Algorithms: should have been pbds but i'm a lazy ass and
// definitely didn't do it

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

ll sum[2], k[2]; // total sum, number of lightningspells
set<int> x[2], lgt;

void add_to_top()
{
	int to_add = *x[0].rbegin();
	x[0].erase(prev(x[0].end()));
	x[1].insert(to_add);
	sum[0]-=to_add;
	sum[1]+=to_add;
	if(lgt.count(to_add))
	{
		k[0]--;
		k[1]++;
	}
}

void rm_frm_top()
{
	int to_rem = *x[1].begin();
	x[1].erase(x[1].begin());
	x[0].insert(to_rem);
	sum[1]-=to_rem;
	sum[0]+=to_rem;
	if(lgt.count(to_rem))
	{
		k[1]--;
		k[0]++;
	}
}

void solve()
{
	int n;
	cin >> n;
	while(n--)
	{
		int tp, d;
		cin >> tp >> d;
		if(d > 0) 
		{
			// everything defaults to "all" set
			sum[0] += d;
			x[0].insert(d);
			if(tp) lgt.insert(d);
			k[0]+=tp;
		} else
		{
			// remove some element
			d=-d;
			int i = x[1].count(d);
			x[i].erase(x[i].find(d));
			sum[i] -= d;
			if(tp) lgt.erase(d);
			k[i]-=tp;
			d=-d;
		}
		while(x[1].size() < lgt.size()) add_to_top();
		while(x[1].size() > lgt.size()) rm_frm_top();
		// update top
		while(x[0].size() && x[1].size() && *x[0].rbegin() > *x[1].begin())
		{
			add_to_top();
			rm_frm_top();
		}
		// if all lightning spells are in the top, we need to remove
		// one of them from top and add one fire spell in its place
		ll ans = sum[0] + 2*sum[1];
		if(lgt.size() == k[1] && lgt.size())
		{
			ans -= *x[1].begin();
			if(x[0].size()) ans += *x[0].rbegin();
		}
		cout << ans << endl;
		cout.flush();
	}
}

int main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
