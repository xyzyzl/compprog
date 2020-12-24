#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)

int n, P[800005], V[800005], st[800005], ans[800005];

void upd(int node, int l, int r, int x, int val)
{
	if (l == r)
	{
		st[node]++;
		ans[l] = val;
		cerr << l << endl;
		return;
	}
	int m = (l + r) / 2;
	// number of slots - the number of people alr sorted
	int X = (m - l + 1) - st[LEFT(node)];
	// if number of slots available is greater than the number of slots needed
	if (X > x)
		upd(LEFT(node), l, m, x, val);
	else
		upd(RIGHT(node), m + 1, r, x - X, val);
	st[node] = st[LEFT(node)] + st[RIGHT(node)];
}

void solve()
{
	while (scanf("%d", &n) != EOF)
	{
		memset(st, 0, sizeof st);
		memset(ans, 0, sizeof ans);
		for (int i = 0; i < n; i++)
		{
			cin >> P[i] >> V[i];
		}
		for (int i = n - 1; i >= 0; i--)
		{
			upd(1, 1, n, P[i], V[i]);
		}
		for (int i = 1; i <= n - 1; i++)
		{
			cout << ans[i] << ' ';
		}
		cout << ans[n] << endl;
	}
}

int main()
{
	solve();
}