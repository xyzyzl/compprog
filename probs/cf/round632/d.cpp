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

int n, k;
vi dir;
void read()
{
	cin >> n >> k;
	dir.resize(n);
	FOR(i, n)
	{
		char c;
		cin >> c;
		dir[i] = (c == 'R');
	}
}

vi find_bad(vi d)
{
	vi ret;
	FOR(i, n-1)
	{
		if(d[i] == 1 && d[i+1] == 0) ret.pb(i);
	}
	return ret;
}

void solve()
{
	int lb = 0, ub = 0, cnt = 0, nxt = 0;
	FORD(i, n)
	{
		if(dir[i])
		{
			ub += cnt;
			lb = max(cnt, nxt + 1);
			nxt = lb;
		} else
		{
			cnt++;
		}
	}
	if(k < lb || k > ub)
	{
		cout << -1 << endl;
		return;
	}

	// need to find the number of head turns
	bool reached = 0;
	vi rem;
	FOR(i, k)
	{
		if(!reached)
		{
			vi bad = find_bad(dir);
			cout << min((int)bad.size(), ub - k + i + 1) << ' ';
			int cur = 0;
			while(k-i-1 < ub && cur < bad.size())
			{
				cout << bad[cur]+1 << ' ';
				dir[bad[cur]] = 0;
				dir[bad[cur]+1] = 1;
				++cur;
				--ub;
			}
			if(ub == k-i-1)
			{
				reached = 1;
				rem = find_bad(dir);
			}
		} else 
		{
			int v = rem.back();
			rem.pop_back();
			cout << "1 " << v+1;
			dir[v] = 0;
			dir[v+1] = 1;
			if(v > 0 && dir[v-1] == 1)
			{
				rem.pb(v-1);
			}
			if(v + 2 < n && dir[v+2] == 0)
			{
				rem.pb(v+1);
			}
		}
		cout << endl;
	}
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
