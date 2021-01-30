#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n, x; cin >> n >> x;
		vector<int> a(n+5), c(n+5);
		for(int i = 0; i < n; i++) cin >> a[i];
		c[n-1] = 1;
		for(int i = n-1; i > 0; i--)
		{
			if(a[i] >= a[i-1]) c[i-1] = c[i];
		}
		int ct = 0;
		for(int i = 0; i < n; i++)
		{
			if(c[i]) break;
			if(a[i] > x)
			{
				swap(a[i], x);
				ct++;
			}
		}
		for(int i = 0; i < n-1; i++)
		{
			if(a[i] > a[i+1])
			{
				cout << -1 << endl;
				goto here;
			}
		}
		cout << ct << endl;
here:
		continue;
	}
}
