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
#define ins insert
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL);                \
	cout.tie(NULL)
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define ll long long
#define MOD ((1e9*1)+7)
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

void solve()
{
	int n, l, r; cin >> n >> l >> r;
	multiset<int> lf, rt;
	FOR(i, l)
	{
		int a; cin >> a;
		lf.ins(a);
	}
	FOR(i, r)
	{
		int b; cin >> b;
		rt.ins(b);
	}
	int cst = 0;
	if(l > r)
	{
		swap(l, r);
		swap(lf, rt);
	}
	// remove alr existing
	F1R(i, n)
	{
		while((lf.find(i) != lf.end()) && (rt.find(i) != rt.end()))
		{
			lf.erase(lf.find(i));
			rt.erase(rt.find(i));
		}
	}
	F1R(i, n)
	{
		auto check = [&i, &rt]()
		{
			bool go = 0;
			if(rt.find(i) != rt.end())
			{
				rt.erase(rt.find(i));
				if(rt.find(i) != rt.end()) go = 1;
				rt.insert(i);
			}
			return go;
		};
		while(check() && (lf.size() < rt.size()))
		{
			rt.erase(rt.find(i));
			rt.erase(rt.find(i));
			cst++; // turn one sock left, but there is a right sock of same color
		}
		if(lf.size() == rt.size()) break;
	}
	// all of different colors now
	// could still have different numbers of things
	int x = (rt.size()-lf.size())/2;
	cout << cst+lf.size()+x*2 << endl;
}

signed main()
{
	// fileio("");
	DUEHOANG;
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
