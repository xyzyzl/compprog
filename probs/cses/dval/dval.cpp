#include <bits/stdc++.h>

using namespace std;

#define bitinc(x) (x&-x)

int n, bit[400005], x[200005];
map<int,int> M;
vector<pair<int, int> > qry[200005];

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
	int q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> x[i];
	for(int i = 0; i < q; i++)
	{
		int a, b; cin >> a >> b;
		qry[a].push_back(make_pair(b,i));
	}
	vector<int> ans(q);
	for(int i = n; i >= 1; i--)
	{
		// only add up to x[i], choosing the earliest appeared instance
		// each time.
		if(M[x[i]]) upd(M[x[i]], -1);
		M[x[i]] = i;
		upd(M[x[i]], 1);
		// find the total number for each query
		for(pair<int,int> t : qry[i])
		{
			ans[t.second] = sum(t.first);
		}
	}
	for(int x : ans) cout << x << endl;
}
