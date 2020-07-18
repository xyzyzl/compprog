// Time:
// Algorithms: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 505

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

#define X 97ll 
#define M 999999929ll

int n, m, p[MAXN];
int sp[MAXN][MAXN], pl[MAXN][MAXN];
int hs[MAXN][MAXN], hp[MAXN][MAXN];
bool good(int len)
{
	if(len == 0) return 1;
	if(len == m+1) return 0;
	FORR(len-1, i, m)
	{
		si tmp, tmp2;
		FOR(j, n)
		{
			if(i < len)
			{
				tmp.insert(hs[j][i]);
				tmp2.insert(hp[j][i]);
			} else 
			{
				tmp.insert(((ll)hs[j][i] - ((ll)hs[j][i-len] * p[len]) % M + M) % M);
				tmp2.insert(((ll)hp[j][i] - ((ll)hp[j][i-len] * p[len]) % M + M) % M);
			}
		}
		int sm = tmp.size() + tmp2.size();
		for(int q : tmp2) tmp.insert(q);
		if(tmp.size() >= sm) return 1; // all distinct
	}
			
	return 0;
}

void precmp()
{
	p[0] = 1;
	F1R(i, m-1)
	{
		p[i] = (ll)(p[i-1] * X) % (ll)M;
	}
	FOR(i, n)
	{
		hs[i][0] = sp[i][0];
		hp[i][0] = pl[i][0];
	}
	FOR(i, n)
	{
		F1R(j, m-1)
		{
			hs[i][j] = ((ll)(X * hs[i][j-1]) % M + (ll)sp[i][j]) % M;
			hp[i][j] = ((ll)(X * hp[i][j-1]) % M + (ll)pl[i][j]) % M;
		}
	}
}

int get(char c)
{
	switch(c) 
	{
		case 'A': return 1;
		case 'C': return 2;
		case 'G': return 3;
		default : return 4;
	}
}

void solve()
{
	cin >> n >> m;
	FOR(i, n)
	{
		FOR(j, m)
		{
			char c;
			cin >> c;
			sp[i][j] = get(c);
		}
	}
	FOR(i, n)
	{
		FOR(j, m)
		{
			char c;
			cin >> c;
			pl[i][j] = get(c);
		}
	}
	precmp();
	int lo = 0, hi = m+1;
	while(lo < hi - 1)
	{
		int mid = (lo+hi)/2;
		if(good(mid)) hi = mid;
		else lo = mid;
	}
	cout << hi << endl;
}

int main()
{
	fileio("cownomics.in", "cownomics.out");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
