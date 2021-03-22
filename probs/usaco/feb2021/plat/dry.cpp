#include <bits/stdc++.h>

using namespace std;
const int MAXN = 200005;
using pii=pair<int, int>;
#define f first
#define s second
#define bitinc(x) (x&-x)

// BIT to keep left endpoints up to i
int n, q, a[MAXN], bit[2*MAXN], ans[MAXN];
vector<pii> qu[MAXN];

int sum(int ind)
{
	int sm = 0;
	while(ind > 0)
	{
		sm += bit[ind];
		ind -= bitinc(ind);
	}
	return sm;
}
void upd(int ind, int val)
{
	while(ind <= n)
	{
		bit[ind] += val;
		ind += bitinc(ind);
	}
}

int main()
{
	cin >> n >> q;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < q; i++)
	{
		int l, r; cin >> l >> r;
		--l; --r;
		qu[r].push_back({l, i});
	}
	// monotonic stack to keep endpoints
	stack<int> stk;
	for(int i = 0; i < n; i++)
	{
		while(!stk.empty() && a[stk.top()] > a[i]) stk.pop();
		if(!stk.empty() && a[stk.top()] == a[i])
		{
			upd(stk.top()+1, 1);
			stk.pop();
			stk.push(i);
		} else 
		{
			stk.push(i);
		}
		for(pii x : qu[i])
		{
			ans[x.s] = i-x.f+1 - sum(i+1)+sum(x.f);
		}
	}
	for(int i = 0; i < q; i++) cout << ans[i] << endl;
}