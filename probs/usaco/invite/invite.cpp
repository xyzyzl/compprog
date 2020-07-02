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

int n, g;
si groups[250005];
vi is_in[MAXN];
void read()
{
	cin >> n >> g;
	FOR(i, g)
	{
		int k;
		cin >> k;
		FOR(j, k)
		{
			int w;
			cin >> w;
			--w;
			groups[i].insert(w);
			is_in[w].pb(i);
		}
	}

}

bool inv[MAXN];
void solve()
{
	qi q;
	q.push(0);
	inv[0] = 1;
	while(!q.empty())
	{
		int tp = q.front();
		q.pop();
		for(int k : is_in[tp]) 
		{
			groups[k].erase(tp);
			if(groups[k].size() == 1)
			{
				int m = *groups[k].begin();
				if(!inv[m])
				{
					inv[m] = 1;
					q.push(m);
					groups[k].erase(groups[k].begin());
				}
			}
		}
	}
	int ret = 0;
	FOR(i, n) if(inv[i]) ++ret;
	cout << ret << endl;
}

int main()
{
	fileio("invite.in", "invite.out");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		read();
		solve();
	}
	
}
