#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int s; cin >> s;
		int mx = 0; // max sum w/ some # digits
		int nd = 0;
		for(int k = 9; k >= 1; k--)
		{
			mx += k;
			nd ++;
			if(mx >= s)
			{
				break;
			}
		}
		// minimize higher pows
		int x = min(9, s), sd = 0;
		int ans = 0;
		int p10 = 1;
		for(int i = 0; i < nd; i++)
		{
			ans += x * p10;
			p10 *= 10;
			sd += x;
			x = min(x-1, s-sd);
		}
		cout << ans << endl;
	}
}