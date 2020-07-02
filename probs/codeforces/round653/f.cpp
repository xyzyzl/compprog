// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 555

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

int n, a[MAXN];
set<int> s;
vi at[MAXN];
bool has_rep;
pii swp;
void read()
{
	swp = mp(-1, -1);
	has_rep = 0;
	s.clear();
	cin >> n;
	FOR(i, MAXN) at[i].clear();
	FOR(i, n)
	{
		cin >> a[i];
		at[a[i]].pb(i);
		if(at[a[i]].size() >= 2)
		{
			swp = mp(at[a[i]].back(), at[a[i]][0]);
			has_rep = 1;
		}
		s.insert(a[i]);
	}
}

int equiv[MAXN], vis[MAXN]; // what is each a[i] equivalent to?

ll bit[2 * MAXN];

int sum(int ind)
{
	int sm = 0;
	while(ind > 0)
	{
		sm += bit[ind];
		ind -= bitinc(ind);
	}
	return sm;
}
void upd(int ind, int val)
{
	while(ind <= n)
	{
	 	bit[ind] += val;
		ind += bitinc(ind);
	}
}

int r[MAXN];
// the number of inversions in r
ll num_inv()
{
	// cerr << "hi" << endl;
	ll ct = 0;
	int mx = 0;
	FOR(i, n)
	{
		bit[i] = 0;
	}
	FORD(i, n)
	{
		// cerr << ct << endl;
		ct += sum(r[i]-1);
		// cerr << "G" << endl;
		upd(r[i], 1);
		// cerr << "h" << endl;
	}
	return ct;
}

void cyc(int i)
{
	swap(r[i+1], r[i+2]);
	swap(r[i], r[i+1]);
}

void solve()
{
	// flatten the array
	int k = 0;
	for(int q : s)
	{
		for(int x : at[q])
		{
			k++;
			r[x] = k;
		}
	}
	ll ok = num_inv();
	if(ok % 2)
	{
		if(!has_rep)
		{
			cout << "-1" << endl;
			return;
		} else 
		{
			int p = swp.f, q = swp.s;
			int x = r[p];
			r[p] = r[q];
			r[q] = x;
		}
	} // otherwise there is nothing to deal with
	vi ans;
	FOR(i, n-2)
	{
		int best = min_element(r+i, r+n)-r;
		while(best > i + 1)
		{
			ans.pb(best-2);
			cyc(best-2);
			best -= 2;
		}
		if(best != i)
		{
			ans.pb(i);
			cyc(i);
			ans.pb(i);
			cyc(i);
			best = i;
		}
	}
	FOR(i, 3)
	{
		if(is_sorted(r, r+n)) break;
		ans.pb(n-3);
		cyc(n-3);
	}
	cout << ans.size() << endl;
	for(int x : ans) cout << x+1 << " ";
	cout << endl;
}

int main()
{
	DUEHOANG;
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		read();
		solve();
	}
	
}
