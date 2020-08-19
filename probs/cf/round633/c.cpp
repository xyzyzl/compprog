#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int prev = 0, ans = 0;
		cin >> prev;
		for(int i = 1; i < n; i++)
		{
			int x;
			cin >> x;
			if(x < prev)
			{
				ans = max(ans, prev-x);
			}
			// cout << x << endl;
			prev = max(prev, x);
		}
		cout << ceil(log2(ans+1)) << endl;
	}
}

