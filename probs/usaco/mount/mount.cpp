// Solution by Albert Ye
// AlphaStar 2020 Summer Camp: CC31AB
// Problem: open10-mount
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	// height, and whether this point is part of a mountain already
	vector<int> a(1+n), vis(1+n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	// max length
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		// only if we're on a decreasing slope that isn't part of a mountain already
		if(a[i+1] < a[i] && !vis[i])
		{
			vis[i] = 1;
			// left traverse
			int lo = i-1;
			for(; lo >= 0 && a[lo] <= a[lo+1]; lo--)
			{
				// add to mountain
				vis[lo] = 1;
			}
			// right traverse
			int hi = i+1;
			for(; hi <  n && a[hi] <= a[hi-1]; hi++)
			{
				// add to mountain
				vis[hi] = 1;
			}
			// maximize width
			ans = max(ans, hi-lo-1);
		}
	}
	cout << ans << endl;
}
