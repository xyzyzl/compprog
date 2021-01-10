#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 200005
#define int long long

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define F1R(i, n) for (int i = 1; i <= n; i++)
#define F1RD(i, n) for (int i = n; i >= 1; i--)
#define pb push_back
#define mp make_pair
#define ins insert
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL);                \
	cout.tie(NULL)
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
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

int ndivs[1000005], divs[1000005][7];
vi primes;

void solve()
{
	int n; cin >> n;
	vector<vi> po(n, vi(7));
	map<vi, int> nodd;
	vector<vi> odds(n);
	vi a(n); FOR(i, n) cin >> a[i];
	int nsq = 0;
	FOR(i, n)
	{
		vi od;
		FOR(j, ndivs[a[i]])
		{
			int x = divs[a[i]][j];
			int y = a[i];
			while(y%x==0)
			{
				y /= x;
				po[i][j]++;
			}
			if(po[i][j] % 2) od.pb(x);
		}
		// for(int x : od) cerr << x << ' ';
		// cerr << endl;
		odds[i] = od;
		if(od.empty()) nsq++;
		nodd[od]++;
	}
	int sq1 = nsq, sq2 = nsq;
	FOR(i, n)
	{
		int same = nodd[odds[i]];
		if(odds[i].empty() || same == 1) continue; // this is impossible.
		if(same % 2)
		{
			sq2++;
		} else
		{
			sq1++;
			sq2++;
		}
	}
	// cerr << nsq << " " << sq1 << " " << sq2 << endl;
	int q; cin >> q;
	while(q--)
	{
		ll w; cin >> w;
		// how to find after w seconds?
		if(w == 0)
		{
			cout << max(nsq, sq1-nsq) << endl;
		} else if(w == 1)
		{
			cout << max(sq1, sq2-sq1) << endl;
		} else
		{
			cout << sq2 << endl;
		}
	}
}

signed main()
{
	memset(ndivs, 0, sizeof ndivs);
	for(int i = 2; i <= 1000000; i++)
	{
		if(!ndivs[i])
		{
			primes.pb(i);
			for(int j = i; j <= 1000000; j+=i)
			{
				divs[j][ndivs[j]++] = i;
			}
		}
	}
	// fileio("");
	DUEHOANG;
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
