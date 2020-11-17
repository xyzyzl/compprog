#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 205

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

int n, q;
string s;
int c[26][1505]; // number of characters in the string
int que[1505][26]; // how good is each query?
void solve()
{
	cin >> n >> s >> q;
	FOR(i, n)
	{
		c[s[i]-'a'][i]++;
		if(i) FOR(j, 26) c[j][i] += c[j][i-1];
	}
	FOR(l, n)
	{
		FORR(l, r, n)
		{
			FOR(i, 26)
			{
				int c_i = c[i][r] - (l ? c[i][l-1] : 0); // number w/ character i
				que[max(r-l+1-c_i, 0)][i] = max(que[max(0, r-l+1-c_i)][i], r-l+1);
			}
		}
	}
	FOR(i, 26) F1R(j, n)
	{
		que[j][i] = max(que[j-1][i], que[j][i]);
	}
	FOR(x,q)
	{
		int ct; char thing;
		cin >> ct >> thing;
		int vl = thing-'a';
		cout << que[ct][vl] << endl;
	}
}

signed main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
