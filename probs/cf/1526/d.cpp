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

map<char, int> ma;
char iv[4] = {'N', 'A', 'T', 'O'};
void solve()
{
	string S; cin >> S;
	int n = S.length();
	// rearrange the permutation + try for each
	vi ct(4);
	FOR(i, n)
	{
		ct[ma[S[i]]]++;
	}
	vector<vi> inv(4, vi(4, 0));
	FOR(i, 4)
	{
		int cur = 0;
		FOR(j, n)
		{
			inv[i][ma[S[j]]] += cur;
			if(ma[S[j]] == i) ++cur;
		}
	}
	vi perm = {0, 1, 2, 3};
	vi ord = {0, 1, 2, 3};
	ll val = -1;
	do 
	{
		// how many swaps do we need to get back to the original string?
		ll curr = 0;
		FOR(i, 4)
		{
			FORR(i+1, j, 4)
			{
				curr += inv[perm[j]][perm[i]]; // need to re-overcome all inversions
			}
		}
		if(curr < 0) cout << "this is a problem" << endl;
		if(curr > val)
		{
			val = curr;
			ord = perm;
		}
	} while(next_permutation(perm.begin(), perm.end()));
	FOR(i, 4)
	{
		FOR(j, ct[ord[i]]) cout << (iv[ord[i]]);
	}
	cout << endl;
}

signed main()
{
	// fileio("");
	DUEHOANG;
	ma['N'] = 0;
	ma['A'] = 1;
	ma['T'] = 2;
	ma['O'] = 3;
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}