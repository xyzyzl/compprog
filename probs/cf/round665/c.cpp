#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; i++) cin >> v[i];
		int mn = INT_MAX;
		vector<int> a,b;
		for(int i = 0; i < n; i++)
		{
			mn = min(mn, v[i]);
		}
		for(int i = 0; i < n; i++)
		{
			if(v[i] % mn == 0)
			{
				a.push_back(v[i]);
				b.push_back(i);
			}
		}
		sort(a.begin(), a.end());
		for(int i = 0; i < a.size(); i++)
		{
			v[b[i]] = a[i];
		}
		bool nondec = 1;
		for(int i = 1; i < n; i++)
		{
			if(v[i] < v[i-1]) nondec = 0;
		}
		cout << (nondec ? "YES" : "NO") << endl;
	}
}
