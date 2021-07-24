#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n; cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	vector<int> d(n);
	int ds = 0;
	vector<int> po;
	vector<int> ne;
	for(int i = 0; i < n; i++)
	{
		ds += (b[i]-a[i]);
		if(b[i]-a[i] > 0)
		{
			for(int j = 0; j < b[i]-a[i]; j++)
			{
				po.push_back(i+1);
			}
		} else 
		{
			for(int j = 0; j < a[i]-b[i]; j++)
			{	
				ne.push_back(i+1);
			}
		}
	}
	if(ds != 0)
	{
		cout << -1 << endl;
		return;
	}
	cout << po.size() << endl;
	for(int i = 0; i < po.size(); i++)
	{
		cout << ne[i] << " " << po[i] << endl;
	}	
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
