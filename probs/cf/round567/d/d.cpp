// Time:
// Algorithms: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace std;
using namespace __gnu_pbds;

#define MAXN 500005

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
#define int ll
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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

int n, m, mf, q, a[MAXN], f[MAXN];
vi frq[MAXN];
ll qry[MAXN], srt[MAXN];
ordered_set os;
map<ll, ll> ret;
void read()
{
	cin >> n >> m >> q;
	FOR(i, n) cin >> a[i]; 
	FOR(i, q)
	{
		cin >> qry[i];
		qry[i] -= n;
		srt[i] = qry[i];
	}
	sort(srt, srt+q);
	sort(a, a+n);
	FOR(i, n)
	{
		f[a[i]]++;
	}
	F1R(i, m)
	{
		frq[f[i]].push_back(i);
		MAX(mf, f[i]);
	}
}

void solve()
{
	int cur = 0, ind = 0;
	F1R(h, mf)
	{
		int pre = cur;
		for(int i : frq[h-1])
		{
			os.insert(i);
		}
		cur += os.size();
		while(srt[ind] != 0 && srt[ind] <= cur)
		{
			ret[srt[ind]] = *os.find_by_order(srt[ind] - pre - 1);
			ind++;
		}
	}
	FOR(i, q)
	{
		if(!ret[qry[i]])
		{
			cout << (qry[i] - cur - 1)%m + 1 << endl;
			continue;
		}
		cout << ret[qry[i]] << endl;
	}
}

signed main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		read();
		solve();
	}	
}

