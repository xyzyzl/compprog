/*input
3 4 2 1
1 2 3 59
*/

#include <bits/stdc++.h>

using namespace std;
using ll=long long;

const int MAXN = 3005;

int n, m, a, b;
ll g0, x, y, z;
ll h[MAXN][MAXN];
deque<ll> deq[MAXN];

// monotonic deque operations
void ins(deque<ll>& d, ll val)
{
	while(!d.empty() && d.back() > val) d.pop_back();
	d.push_back(val);
}

void del(deque<ll>& d, ll val)
{
	if(!d.empty() && d.front() == val)
		d.pop_front();
}

int main()
{
	cin >> n >> m >> a >> b;
	cin >> g0 >> x >> y >> z;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
	{
		h[i][j] = g0;
		g0 = (g0*x+y)%z;
	}
	// min deque time
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < a; j++)
		{
			ins(deq[i], h[j][i]);
		}
	}
	deque<ll> deq2;
	ll ans = 0;
	for(int i = 0; i < b; i++)
	{
		ins(deq2, deq[i].front());
	}
	ans += deq2.front();
	for(int i = b; i < m; i++)
	{
		del(deq2, deq[i-b].front());
		ins(deq2, deq[i].front());
		ans += deq2.front();
	}
	for(int i = a; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			ins(deq[j], h[i][j]);
			del(deq[j], h[i-a][j]);
		}
		deque<ll> deq3;
		for(int j = 0; j < b; j++)
		{
			ins(deq3, deq[j].front());
		}
		ans += deq3.front();
		for(int j = b; j < m; j++)
		{
			del(deq3, deq[j-b].front());
			ins(deq3, deq[j].front());
			ans += deq3.front();
		}
	}
	cout << ans << endl;
}