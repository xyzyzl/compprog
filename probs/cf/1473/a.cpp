#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n; vector<int> v(n);
		int k; cin >> k;
		for(int i = 0; i < n; i++) cin >> v[i];
		sort(v.begin(), v.end());
		int sm = v[0]+v[1];
		if(sm > k)
		{
			bool ok = 1;
			for(int x : v)
			{
				if(x > k) ok = 0;
			}
			cout << (ok ? "yes" : "no") << endl;
		} else
		{
			cout << "YES" << endl;
		}
		
	}
}