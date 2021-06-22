#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int n, q;
long long x[MAXN], ps[MAXN], v[MAXN], bit[MAXN];
#define bitinc(x) (x&-x)
long long sum(int ind)
{
	long long sm = 0;
	while(ind > 0)
	{
		sm += bit[ind];
		ind -= bitinc(ind);
	}
	return sm;
}
void upd(int ind, long long val)
{
	while(ind <= n)
	{
		bit[ind] += val;
		ind += bitinc(ind);
	}
}
vector<pair<int, int> > qr[MAXN];
int main()
{
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> x[i];
		ps[i] = x[i] + ps[i-1];
	}
	for(int i = 0; i < q; i++)
	{
		int a, b; cin >> a >> b;
		qr[a].push_back({b, i});
	}
	deque<long long> st;
	st.push_front(n+1);
	x[n+1] = 1e18+7;
	ps[n+1] = ps[n] + x[n+1];
	vector<long long> ans(q);
	for(int i = n; i > 0; i--)
	{
		while(st.size() && x[st.front()] <= x[i])
		{
			upd(st.front(), -v[st.front()]);
			st.pop_front();
		}
		v[i] = (st.front() - 1 - i) * x[i] - (ps[st.front()-1] - ps[i]);
		upd(i, v[i]);
		// cerr << st.front() << endl;
		st.push_front(i);
		for(auto p : qr[i])
		{
			int pos = prev(upper_bound(st.begin(), st.end(), p.first)) - st.begin();
			// cerr << pos << " " << st[pos] << " " << p.first << endl;
			ans[p.second] = (pos ? (sum(st[pos-1]) - sum(i-1)) : 0) + (p.first - st[pos]) * x[st[pos]]
				- (ps[p.first]-ps[st[pos]]);
		}
	}
	for(int i = 0; i < q; i++) cout << ans[i] << endl;
}