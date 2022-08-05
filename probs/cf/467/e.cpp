#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500005;
int n, a[MAXN];
map<int, int> las, rep; 
vector<int> ms;
int main()
{
	cin >> n;
	vector<int> ans;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(las.count(a[i]))
		{
			ans.push_back(las[a[i]]);
			ans.push_back(a[i]);
			ans.push_back(las[a[i]]);
			ans.push_back(a[i]);
			las.clear();
			ms.clear();
			rep.clear();
			continue;
		} else if(rep[a[i]])
		{
			// is the second time a[i] appears
			int rem = (rep[a[i]] >= 2) ? 1 : 0; // has remaining pair after we're done with current value
			while(rem || ms.back() != a[i])
			{
				if(ms.back() == a[i]) rem--;
				las[ms.back()] = a[i];
				ms.pop_back();
			}
		}
		rep[a[i]]++;
		ms.push_back(a[i]);
	}
	cout << ans.size() << endl;
	for(int x : ans)
	{
		cout << x << " ";
	}
	cout << endl;
}