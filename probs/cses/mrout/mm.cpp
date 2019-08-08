#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie();                    \
	cout.tie()

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

int n, m, d[MAXN], p[MAXN];
vi adj[MAXN];
void bfs()
{
	qi q;
	q.push(0);
	d[0] = 1;
	p[0] = -1;
	while(!q.empty())
	{
		int fr = q.front();
		q.pop();
		for(int nx : adj[fr])
		{
			if(nx != p[fr] && d[nx] > d[fr]+1)
			{
				p[nx] = fr;
				d[nx] = d[fr]+1;
				q.push(nx);
			}
		}
	}
}
int main()
{
	DUEHOANG;
	cin >> n >> m;
	fill(d, d+n, INT_MAX);
	FOR(i, m)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	bfs();
	if (d[n - 1] == INT_MAX)
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	cout << d[n - 1] << endl;
	int i = n - 1;
	vi aw;
	aw.pb(n);
	while (p[i] != -1)
	{
		aw.pb(p[i] + 1);
		i = p[i];
	}
	reverse(aw.begin(), aw.end());
	for (int anime : aw)
		cout << anime << " "; // anime is my only escape from this bullshit called
	// Arlen, Texas
	
}