#include <bits/stdc++.h>

using namespace std;

int n, a[5005];

int rec(int l, int r)
{
	if(l>r) return 0;
	// cerr << l << " " << r << endl;
	int mn = INT_MAX, j = l;
	for(int i = l; i <= r; i++) 
	{
		if(mn > a[i])
		{
			mn=a[i];
			j=i;
		}
	}
	int k = 0;
	if(l-1 >= 0) k = max(k, a[l-1]);
	k = max(k, a[r+1]);
	return min(r-l+1, rec(l, j-1) + rec(j+1, r)+mn-k);
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	cout << rec(0,n-1) << endl;
}
