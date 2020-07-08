// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 100005

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

int n, m, r[2*MAXN];
pii inds[MAXN];
mii to;
mii inv;

ll bit[4 * MAXN];

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
	while(ind <= m)
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
	memset(bit, 0, sizeof bit);
	FORD(i, m)
	{
		// cerr << ct << endl;
		int q = sum(r[i]-1);
		ct += q;
		// cerr << "G" << endl;
		upd(r[i], 1);
		// cerr << "h" << endl;
	}
	return ct;
}

si exist;
void read()
{
	cin >> n;
	FOR(i, n)
	{
		cin >> inds[i].f >> inds[i].s;
		to[inds[i].f] = inds[i].f;
		to[inds[i].s] = inds[i].s;
		exist.insert(inds[i].f);
		exist.insert(inds[i].s);
	}	
	FOR(i, n)
	{
		int x = to[inds[i].f];
		int y = to[inds[i].s];
		to[inds[i].f] = y;
		to[inds[i].s] = x;
	}
	int ind = 0;
	for(int x : exist)
	{
		r[ind] = to[x];
		inv[to[x]] = ind;
		ind++;
	}
	m = ind;
	// compress r because otherwise too big
	si q;
	FOR(i, m)
	{
		q.insert(r[i]);
	}
	mii mq;
	ind = 0;
	for(int x : q)
	{
		mq[x] = ++ind;
	}
	FOR(i, m) r[i] = mq[r[i]];
	/*
	FOR(i, m) cerr << r[i] << " ";
	cerr << endl;
	*/
}

void solve()
{
	ll ret = num_inv();
	cerr << ret << endl;
	mii link;
	FOR(i, n)
	{
		link[inds[i].f] = inds[i].s;
		link[inds[i].s] = inds[i].f;
	}
	for(int i : exist)
	{
		int p = max(inv[to[i]], inv[to[link[i]]]);
		int q = min(inv[to[i]], inv[to[link[i]]]);
		int pp = max(to[i], to[link[i]]);
		int qq = min(to[i], to[link[i]]);
		int rr = pp-qq-1;
		// find # indices in between that have alr been swapped
		ll x = rr - (p-1-q);
		ret += x;
	}
	cout << ret << endl;
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