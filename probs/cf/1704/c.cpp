#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n, m; cin >> n >> m;
		vector<int> a(m);
		for(int i = 0; i < m; i++)
		{
			cin >> a[i];
		}
		if(n == m)
		{
			cout << n << endl;
			continue;
		}
		sort(a.begin(), a.end());
		vector<int> d;
		for(int i = 0; i < m-1; i++)
		{
			d.push_back(a[i+1]-a[i]-1);
		}
		d.push_back(n + a[0] - a[m-1] - 1);
		sort(d.begin(), d.end());
		int st = upper_bound(d.begin(), d.end(), 2) - d.begin();
		if(st == d.size())
		{
			cout << n-1 << endl; // can only remove one without the rest coming undone
			continue;
		}
		// protecting a range takes 1 away from that range, while also taking away 4 from all other ranges.
		int save = 0; // add d[i]-1-4*ts unless d[i]-4*ts=1 in which case just do d[i]-4*ts
		int ts = 0; // subtract 4*ts
		st = upper_bound(d.begin(), d.end(), 3) - d.begin();
		if(st == d.size())
		{
			cout << n-2 << endl;
			continue;
		}
		for(int j = d.size()-1; j >= 0; j--)
		{
			save += max(0, d[j] - 1 - 4*ts);
			// cerr << d[j] << " " << ts << endl;
			if(d[j] - 4*ts == 1) save++;
			ts++;
		}
		cout << n-save << endl;
	}
}