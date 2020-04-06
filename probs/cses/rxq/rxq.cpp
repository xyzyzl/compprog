// OMG WORKS！!!!!!!!!!!
#include <bits/stdc++.h>

#define bitinc(x) x&-x
#define int long long

using namespace std;

#define LEFT(x) 2*x
#define RIGHT(x) 2*x+1

#define INF 1e15+7

int st[800005], arr[200005];
int n, q;

void build(int node, int a, int b) {
	if (a > b) return;
	if (a == b) {
		st[node] = arr[a];
		return;
	}
	build(LEFT(node), a, (a + b) / 2);
	build(RIGHT(node), (a + b) / 2 + 1, b);

	st[node] = st[LEFT(node)] ^ st[RIGHT(node)];
}

int rmq(int node, int a, int b, int i, int j) {
	if (a > b || a > j || b < i) return 0;
	if (a >= i && b <= j) return st[node];

	int q1 = rmq(LEFT(node), a, (a + b) / 2, i, j);
	int q2 = rmq(RIGHT(node), (a + b) / 2 + 1, b, i, j);
	return q1 ^ q2; // this operation will change if it becomes something else
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
    st[node] = st[LEFT(node)] ^ st[RIGHT(node)];
}

signed main()
{
	// freopen("r.in", "r", stdin);
	cin >> n >> q;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		// upd(i, arr[i]);
	}
	build(1, 0, n-1);
	while(q--)
	{
		int t = 2;
		// cin >> t;
		if(t == 1)
		{
			int k;
			long long u;
			cin >> k >> u;
			--k;
			upd(1, 0, n-1, k, u);
		} else 
		{
			int a, b;
			cin >> a >> b;
			--b; --a;
			cout << rmq(1, 0, n-1, a, b) << endl;
		}
	}
}