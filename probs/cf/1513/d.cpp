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
#define int long long
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

class UnionFind
{
private:
	vector<int> p, rank;
public:
	UnionFind(int N)
	{
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++)
			p[i] = i;
	}
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
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y])
				p[y] = x;
			else
			{
				p[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
};

void solve()
{
	int n;
	ll p;
	cin >> n >> p;
	UnionFind uf(n);
	vi b(n);
	vii a(n);
	FOR(i, n)
	{
		cin >> a[i].f;
		b[i] = a[i].f;
		a[i].s = i;
	}
	sort(a.begin(), a.end());
	ll ans = 0;
	FOR(i, n)
	{
		if(a[i].f >= p) break;
		int v = a[i].f, j = a[i].s;
		while(j > 0)
		{
			if(uf.isSameSet(j-1, j)) break;
			if(b[j-1]%v==0)
			{
				ans += v;
				uf.unionSet(j-1, j);
				--j;
			} else break;
		}
		j = a[i].s;
		while(j < n-1)
		{
			if(uf.isSameSet(j+1, j)) break;
			if(b[j+1]%v==0)
			{
				ans += v;
				uf.unionSet(j+1, j);
				++j;
			} else break;
		}
	}
	set<int> q;
	FOR(i, n)
	{
		q.insert(uf.findSet(i));
	}
	ans += p*(q.size()-1);
	cout << ans << endl;
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
