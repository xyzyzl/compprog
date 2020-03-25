// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1000005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
#define FOBIRD(i, n) for (int i = n; i >= 1; i--)
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

int n, p[MAXN], q[MAXN], r[MAXN];
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

void solve()
{
	DUEHOANG;
	// cerr << "b" << endl;
	cin >> n;
	FOR(i, n)
	{
		int a;
		cin >> a;
		p[a] = i;
	}
	// cerr << "bruh" << endl;
	FOR(i, n)
	{
		int b;
		cin >> b;
		q[b] = i;
	}
	// cerr << "bruh" << endl;
	FOBIR(i, n)
	{
		r[p[i]] = q[i]+1;
	}
	// compute the number of inversions in r
	ll best = num_inv(), run = best;
	// cout << best << endl;
	// see what happens with each cyclic shift
	FORD(i, n)
	{
		run += (2*r[i]-n-1);
		best = min(best, run);
	}
	FOBIR(i, n)
	{
		r[q[i]] = p[i]+1;
	}
	// need to do it for the q-side also!
	ll good = num_inv();
	run = good;
	FORD(i, n)
	{
		run += (2*r[i]-n-1);
		good = min(good, run); // essentially copy + paste
	}
	cout << min(best, good) << endl;
}

int main()
{
	fileio("mincross.in", "mincross.out");
	// cout << "a" << endl;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		// cout << "blah" << endl;
		solve();
	}
}

