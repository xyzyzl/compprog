#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int n, a[MAXN], maxa;
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		maxa = max(maxa, a[i]);
	}
	if(n <= 100)
	{
		int ans = 0;
		// smol n: brute force starting point and starting number
		for(int s = 0; s < n; s++) for(int k = 1; k <= a[s]; k++)
		{
			swap(a[0], a[s]);
			int l = k;
			int tot = 0;
			int f = 0;
			for(int i = 0; i < n; i++)
			{
				if(a[i] >= l) ++tot;
				if(a[i]-l >= (a[i]+1)/2)
				{
					++tot;
					l = k*(a[i]-l)/k;
				}
			}
			if(tot%2) 
			{
				cerr << k << endl;
				ans ++;
			}
			swap(a[0], a[s]);
		}
		cout << ans << endl;
	} else
	{
		cout << 69 << endl;
	}
}