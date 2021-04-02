#include <bits/stdc++.h>

#define LEFT(x) (2*x)
#define RIGHT(x) (2*x+1)

using namespace std;
using ll=long long;
const ll INF = 1e15+5;

const int MAXN = 300005;

int n, h[MAXN], b[MAXN], pre[MAXN];
ll dp[MAXN], st[4*MAXN];

void build(int node, int a, int b) {
	if (a > b) return;
	if (a == b) {
		st[node] = -INF;
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
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> h[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	stack<pair<int, int> > mono;
	build(1, 0, n);
	upd(1, 0, n, 0, 0); // set the original to 0
	for(int i = 1; i <= n; i++)
	{
		while(!mono.empty() && mono.top().first >= h[i])
		{
			mono.pop();
		}
		if(!mono.empty()) pre[i] = mono.top().second;
		else pre[i] = 0;
		ll pdp = rmq(1, 0, n, pre[i], i-1);
		dp[i] = pdp + b[i];
		if(pre[i]) dp[i] = max(dp[i], dp[pre[i]]);
		upd(1, 0, n, i, dp[i]);
		mono.push({h[i], i});
	}
	cout << dp[n] << endl;
}