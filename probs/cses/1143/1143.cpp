#include <bits/stdc++.h>
#define LEFT(x) (2*x)
#define RIGHT(x) (2*x+1)
#define ll long long
const ll INF = 1e15+7;

using namespace std;

const int MAXN = 200005;

int n, m;
ll h[MAXN], r[MAXN];

ll st[4*MAXN];
void build(int node, int a, int b) {
	if (a > b) return;
	if (a == b) {
		st[node] = h[a];
		return;
	}
	build(LEFT(node), a, (a + b) / 2);
	build(RIGHT(node), (a + b) / 2 + 1, b);

	st[node] = max(st[LEFT(node)], st[RIGHT(node)]);
}

ll rmq(int node, int a, int b, int i, int j) {
	if (a > b || a > j || b < i) return -INF;
	if (a >= i && b <= j) return st[node];

	ll q1 = rmq(LEFT(node), a, (a + b) / 2, i, j);
	ll q2 = rmq(RIGHT(node), (a + b) / 2 + 1, b, i, j);
	return max(q1, q2); // this operation will change if it becomes something else
}

void upd(int node, int a, int b, int x, ll value)
{
    if(a == b)
    {
        st[node] = value;
        return;
    }

    if(x <= (a+b)/2) upd(LEFT(node), a, (a+b)/2, x, value);
    else upd(RIGHT(node), (a+b)/2+1, b, x, value);
    st[node] = max(st[LEFT(node)], st[RIGHT(node)]);
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> h[i];
	}
	for(int j = 0; j < m; j++)
	{
		cin >> r[j];
	}
	build(1, 0, n-1);
	for(int j = 0; j < m; j++)
	{
		int lo = -1, hi = n;
		while(lo+1 < hi)
		{
			// use rmq to check if rmq(mid) < r[j] or not
			int mid = (lo + hi)/2;
			if(rmq(1, 0, n-1, 0, mid) >= r[j])
				hi = mid;
			else 
				lo = mid;
		}
		cout << (hi == n ? 0 : hi+1) << ' ';
		if(hi < n)
		{
			upd(1, 0, n-1, hi, h[hi] - r[j]);
			h[hi] = h[hi] - r[j];
		}
	}
	cout << endl;
}