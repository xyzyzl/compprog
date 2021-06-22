#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;
const int INF = 1e9 + 7;

#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)

int n, q, p[MAXN];
struct ST
{
	int n, arr[MAXN], st[4 * MAXN];
	void build(int node, int a, int b)
	{
		if (a > b)
			return;
		if (a == b)
		{
			st[node] = arr[a];
			return;
		}
		build(LEFT(node), a, (a + b) / 2);
		build(RIGHT(node), (a + b) / 2 + 1, b);

		st[node] = min(st[LEFT(node)], st[RIGHT(node)]);
	}

	int rmq(int node, int a, int b, int i, int j)
	{
		if (a > b || a > j || b < i)
			return INF;
		if (a >= i && b <= j)
			return st[node];

		int q1 = rmq(LEFT(node), a, (a + b) / 2, i, j);
		int q2 = rmq(RIGHT(node), (a + b) / 2 + 1, b, i, j);
		return min(q1, q2); // this operation will change if it becomes something else
	}

	int rmq(int i, int j)
	{
		return rmq(1, 0, n - 1, i, j);
	}

	void upd(int node, int a, int b, int x, int value)
	{
		if (a == b)
		{
			st[node] = value;
			return;
		}

		if (x <= (a + b) / 2)
			upd(LEFT(node), a, (a + b) / 2, x, value);
		else
			upd(RIGHT(node), (a + b) / 2 + 1, b, x, value);
		st[node] = min(st[LEFT(node)], st[RIGHT(node)]);
	}

	void upd(int k, int x)
	{
		upd(1, 0, n-1, k, x);
	}

	ST(vector<int> a)
	{
		n = a.size();
		for (int i = 0; i < n; i++)
		{
			arr[i] = a[i];
		}
		build(1, 0, n - 1);
	}
	ST()
	{
	}
} st1, st2;

void upp(int k)
{
	st1.upd(k, p[k]-k);
	st2.upd(k, p[k]+k);
}

int main()
{
	cin >> n >> q;
	vector<int> filler(n);
	st1 = ST(filler);
	st2 = ST(filler);
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		upp(i);
	}
	while (q--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int k, x;
			cin >> k >> x;
			--k;
			p[k] = x;
			upp(k);
		} else 
		{
			int k; cin >> k; --k;
			int be = st1.rmq(0, k) + k;
			int ab = st2.rmq(k,n-1) - k;
			cout << min(be, ab) << endl;
		}
	}
}