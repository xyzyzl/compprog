#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, h, m, k;
	cin >> n >> h >> m >> k;
	vector<int> H(n), M(n), mm(n);
	for(int i = 0; i < n; i++)
	{
		cin >> H[i] >> M[i];
		mm[i] = M[i] % (m/2);
	}
	vector<pair<int, pair<int, int> > > swp;
	for(int i = 0; i < n; i++)
	{
		if(mm[i]+k-1 >= m/2)
		{
			swp.push_back(make_pair(mm[i]+1, make_pair(0, i)));
			swp.push_back(make_pair(m/2, make_pair(1, i)));
			swp.push_back(make_pair(0, make_pair(0, i)));
			swp.push_back(make_pair((mm[i]+k)%(m/2), make_pair(1, i)));
		}
		else
		{
			swp.push_back(make_pair(mm[i]+1, make_pair(0, i)));
			swp.push_back(make_pair(mm[i]+k, make_pair(1, i)));
		}
	}
	int ct = INT_MAX;
	int a = 0, b = 0;
	sort(swp.begin(), swp.end());
	for(int i = 0; i < swp.size(); i++)
	{
		if(swp[i].second.first == 0)
		{
			a++;
		} else 
		{
			a--;
		}
	 	if(i < n-1 && swp[i].first == swp[i+1].first) continue;
		if(swp[i].first >= m/2) continue;
		if(ct > a) 
		{
			ct = a;
			b = swp[i].first;
		}
	}
	vector<int> ans;
	for(int i = 0; i < n; i++)
	{
		if(mm[i]+k-1 >= m/2)
		{
			if(b > mm[i] || b < (mm[i]+k)%(m/2))
			{
				ans.push_back(i+1);
			}
		} else 
		{
			if(b > mm[i] && b < (mm[i]+k))
			{
				ans.push_back(i+1);
			}
		}
	}
	cout << ans.size() << " " << b << endl;
	for(int x : ans) cout << x << endl;
}
