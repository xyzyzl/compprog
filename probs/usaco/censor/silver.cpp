// Time:
// Algorithms: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
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

int n, m, p[MAXN], tv, th[MAXN];
string s, t, ans;
vi h;

void precmp()
{
	p[0] = 1;
	F1R(i, n-1)
	{
		p[i] = (p[i-1] * X) % M;
	}
	th[0] = (t[0] - 'a' + 1);
	F1R(i, m-1)
	{
		th[i] = ((th[i-1] * X) % M + (t[i] - 'a' + 1)) % M;
	}
	tv = th[m-1];
}

void solve()
{
	cin >> s >> t;	
	n = s.size();
	m = t.size();
	precmp();
	int k = 1;
	h.pb(0);
	FOR(i, n)
	{
		ans += s[i];
		h.pb(((h.back() * X) % M + (s[i] - 'a' + 1)) % M);
		if(k == m-1)
		{
			if(h.back() == tv)
			{
				ans.resize(ans.size() - m);
				h.resize  (  h.size() - m);
				k -= m;
			}
		} else if(k >= m)
		{
			ll sv = ((ll)h[k] - ((ll)h[k-m] * (ll)p[m]) % M + M) % M;
			if(sv == tv) 
			{
				ans.resize(ans.size() - m);
				h.resize  (  h.size() - m);
				k -= m;
			}
		}
		k++;
	}
	cout << ans << endl;
}

int main()
{
	fileio("censor.in", "censor.out");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
