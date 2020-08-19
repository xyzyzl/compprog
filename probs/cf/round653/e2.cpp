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
#define INF (2e9*1)+500

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

int n,m,k;
vii all, AB, A, B;
vi ans;

int place(int cnt, vi &v)
{
	vi vis(n);
	int ret = 0;
	int q = 0, a_rem = k, b_rem = k;
	for(pii x : AB)
	{
		if(q < cnt && a_rem && b_rem)
		{
			ret += x.f;
			++q;
			--a_rem;
			--b_rem;
			vis[x.s] = 1;
			v.pb(x.s);
		}
	}
	for(pii x : A)
	{
		if(a_rem)
		{
			ret += x.f;
			++q;
			--a_rem;
			v.pb(x.s);
			vis[x.s] = 1;
		}
	}
	for(pii x : B)
	{
		if(b_rem)
		{
			ret += x.f;
			++q;
			--b_rem;
			v.pb(x.s);
			vis[x.s] = 1;
		}
	}
	// now check all remaining
	for(pii x : all)
	{
		if(vis[x.s]) continue;
		if(q == m) break; // no more
		++q;
		ret += x.f;
		v.pb(x.s);
		vis[x.s] = 1;
	}
	if(a_rem || b_rem || (q != m)) return INF;
	return ret;
}

int tern(int lo, int hi)
{
	int ret = INF;
	vi v;
	if(hi <= 2) // can't do tern. search
	{
		// just do lin. search
		FOR(i, hi+1)
		{
			// run E1 algorithm
			int tmp = place(i, v);
			if(tmp < ret)
			{
				ret = tmp;
				ans = v;
			}
			v.clear();
		}
		return ret;
	}
	int m1, m2;
	while(lo < hi - 2)
	{
		m1 = lo + (hi-lo)/3;
		m2 = hi - (hi-lo)/3;
		vi dummy1, xyzyzl; // dummies
		int a_1 = place(m1, dummy1);
		int a_2 = place(m2, xyzyzl);
		// real
		if(a_1 == INF && a_2 == INF) a_1++;
		if(a_1 <= a_2)
		{
			hi = m2;
			MIN(ret, a_1);
		} else
		{
			lo = m1;
		}
	}
	ret = place(lo, v);
	ans = v;
	v.clear();
	FORR(lo, i, hi+1)
	{
		// run E1 algorithm
		int tmp = place(i, v);
		if(tmp < ret)
		{
			ret = tmp;
			ans = v;
		}
		v.clear();
	}
	
	return ret;	
}

void read()
{
	cin >> n >> m >> k;
	FOR(i, n)
	{
		int q, a, b;
		cin >> q >> a >> b;
		if(a && b) AB.pb(mp(q, i));
		else if(a) A.pb(mp(q, i));
		else if(b) B.pb(mp(q, i));
		all.pb(mp(q, i));
	}
}

void solve()
{
	sort(AB.begin(), AB.end());
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(all.begin(), all.end());
	int x = tern(0, AB.size()); // ternary search on # mutual books
	if(x == INF)
	{
		cout << -1 << endl;
		return;
	}
	cout << x << endl;
	for(int i : ans) cout << 1+i << " ";
	cout << endl;
}

int main()
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
