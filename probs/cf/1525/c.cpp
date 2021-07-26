#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300005;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> ans(n,-1);
	vector<pair<int, pair<int, int> > > A(n);
	stack<int> sta[2];
	for(int i = 0; i < n; i++)
	{
		cin >> A[i].first;
	}
	for(int i = 0; i < n; i++)
	{
		char c; cin >> c;
		if(c == 'L') A[i].second.first = 0;
		else A[i].second.first = 1;
		A[i].second.second = i;
	}
	sort(A.begin(), A.end());
	for(int i = 0; i < n; i++)
	{
		int j = A[i].first%2;
		if(A[i].second.first)
		{
			sta[j].push(i);
		} else 
		{
			if(sta[j].empty())
				sta[j].push(i);
			else 
			{
				int k = sta[j].top();
				sta[j].pop();
				ans[A[i].second.second] = ans[A[k].second.second] = (A[i].first - A[k].first + 2*A[k].first*(1-A[k].second.first))/2;
			}
		}
	}
	for(int p = 0; p < 2; p++)
	{
		while(sta[p].size() > 1)
		{
			int i = sta[p].top();
			sta[p].pop();
			int j = sta[p].top();
			sta[p].pop();
			ans[A[i].second.second] = ans[A[j].second.second] = (2*m - A[i].first - A[j].first + 2*A[j].first*(1-A[j].second.first))/2;
		}
	}
	for(int i = 0; i < n; i++) cout << ans[i] << " ";
	cout << endl;
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
