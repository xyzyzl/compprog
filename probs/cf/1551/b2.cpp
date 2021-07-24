/*input
6
10 3
3 1 1 1 1 10 3 10 10 2
4 4
1 1 1 1
1 1
1
13 1
3 1 4 1 5 9 2 6 5 3 5 8 9
13 2
3 1 4 1 5 9 2 6 5 3 5 8 9
13 3
3 1 4 1 5 9 2 6 5 3 5 8 9
*/

#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n, k; cin >> n >> k;
	vector<int> a(n), freq(n+4);
	vector<vector<int> > flist(n+4);
	vector<int> ans(n, 0);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		freq[a[i]]++;
		flist[a[i]].push_back(i);
	}
	vector<int> li;
	for(int i = 1; i <= n; i++)
	{
		if(freq[i] >= k)
		{
			for(int j = 0; j < min(freq[i], k); j++)
			{
				ans[flist[i][j]] = 1+j;
			}
			freq[i] = 0;
			continue;
		}
		else 
		{
			for(int j = 0; j < freq[i]; j++)
			{
				li.push_back(flist[i][j]);
			}
		}
	}
	for(int j = 0; j < li.size(); j += k)
	{
		if(j + k - 1 >= li.size()) break;
		for(int l = 0; l < k; l++)
		{
			ans[li[j+l]] = 1+l;
		}
	}
	for(int i = 0; i < n; i++) cout << ans[i] << " ";
	cout << endl;
}

int main()
{
	int t; cin >> t;
	while(t--)
		solve();
}