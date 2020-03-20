/*input
3
1 4 6
*/
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

int n, a[MAXN], sd[MAXN], dist[MAXN]; // the <=2 prime divisors of a[i]
vi adj[MAXN], d[MAXN], primes;
vector<vi> arr;

void solve()
{
	cin >> n;	
	// try to run sieve but like
	ll MN = 1000000;
	primes.pb(1);
	FORR(2, i, MN+1)
	{
		if(!sd[i])
		{
			primes.pb(i);
			for(int j = i; j <= MN; j+=i) sd[j] = i;
		}
		d[i] = d[i/sd[i]];
		auto div = find(d[i].begin(), d[i].end(), sd[i]); // is the first divisor alr in
		if(div != d[i].end()) d[i].erase(div); // get rid of it if it is
		else d[i].pb(sd[i]); // add it if it isn't
	}
	int mx = 0;
	FOR(i, n)
	{
		int a;
		cin >> a;
		if(d[a].empty())
		{
			cout << 1 << endl;
			return;
		}
		if(d[a].size() == 1)
		{
			d[a].pb(1);
		}
		arr.pb({d[a][0], d[a][1]});
		adj[d[a][0]].pb(i);
		adj[d[a][1]].pb(i);
	}
	int ret = INF;
	for(int i : primes)
	{
		if(i * i > MN)
		{
			break;
		}
		// cerr << i << endl;
		for(int j : primes) dist[j] = 0;
		queue<pii> q;
		for(int j : adj[i])
		{
			q.push(mp(j, arr[j][0] == i));
			dist[arr[j][0]^arr[j][1]^i] = 1;
		}
		while(!q.empty())
		{
			auto p=q.front();
			q.pop();
			int cur = arr[p.f][p.s];
			// cerr << cur << " " << i << endl;
			for(int u : adj[cur])
			{
				if(u != p.f)
				{
					pii fuck_this_stupid_problem = mp(u, arr[u][0]==cur);
					int nxt = arr[fuck_this_stupid_problem.f][fuck_this_stupid_problem.s];
					if(!dist[nxt] && nxt != i)
					{
						q.push(fuck_this_stupid_problem);
						dist[nxt] = dist[cur]+1;
					}
					else
					{
						MIN(ret, dist[cur] + dist[nxt] + 1);
					}
				}
			}
		}
	}
	if(ret == INF) ret = -1;
	cout << ret << endl;
}

int main()
{
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
