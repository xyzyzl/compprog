/*input
6 5
1 2 1 3 2 3
4 6
1 3
2 5
2 4
1 6
*/

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
#define f first
#define s second

const int MAXN = 500005;
const int INF = 1e9+7;

#define LEFT(x) (2*x)
#define RIGHT(x) (2*x+1)

int n, m, a[MAXN], nxt[MAXN], st[4*MAXN], ans[MAXN];
vector<pii> qry[MAXN];

void build(int node, int a, int b) {
	if (a > b) return;
	if (a == b) {
		st[node] = INF;
		return;
	}
	build(LEFT(node), a, (a + b) / 2);
	build(RIGHT(node), (a + b) / 2 + 1, b);

	st[node] = min(st[LEFT(node)], st[RIGHT(node)]);
}

int rmq(int node, int a, int b, int i, int j) {
	if (a > b || a > j || b < i) return INF;
	if (a >= i && b <= j) return st[node];

	int q1 = rmq(LEFT(node), a, (a + b) / 2, i, j);
	int q2 = rmq(RIGHT(node), (a + b) / 2 + 1, b, i, j);
	return min(q1, q2); // this operation will change if it becomes something else
}

void upd(int node, int a, int b, int x, int value)
{
	if(a == b)
	{
		st[node] = value;
		return;
	}

	if(x <= (a+b)/2) upd(LEFT(node), a, (a+b)/2, x, value);
	else upd(RIGHT(node), (a+b)/2+1, b, x, value);
	st[node] = min(st[LEFT(node)], st[RIGHT(node)]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	map<int, int> last;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		last[a[i]] = -1;
	}
	memset(nxt, -1, sizeof nxt);
	for(int i = 0; i < n; i++)
	{
		if(last[a[i]] != -1)
			nxt[last[a[i]]] = i;
		last[a[i]] = i;
	}
	// offline queries
	for(int i = 0; i < m; i++)
	{
		int l, r; cin >> l >> r;
		--l; --r;
		qry[l].push_back({r, i});
	}
	build(1, 0, n-1);
	for(int i = n-1; i >= 0; i--)
	{
		if(nxt[i] != -1)
		{
			// add {i, nxt[i]} as a range w/ distance nxt[i]-i
			upd(1, 0, n-1, nxt[i], nxt[i]-i);
		}
		for(auto x : qry[i])
		{
			// then just do rmq on the distances!
			int k = rmq(1, 0, n-1, i, x.f);
			if(k == INF)
			{
				ans[x.s] = -1;
			} else 
			{
				ans[x.s] = k;
			}
		}
	}
	for(int i = 0; i < m; i++) cout << ans[i] << endl;
}