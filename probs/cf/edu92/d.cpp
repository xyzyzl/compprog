#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long n, k, l1, r1, l2, r2;
		cin >> n >> k >> l1 >> r1 >> l2 >> r2;
		long long L1 = min(l1, l2);
		long long L2 = max(l1, l2);
		long long R1 = min(r1, r2);
		long long R2 = max(r1, r2);
		long long ans = 0;
		long long val = 0;
		if(L2 - R1 > 0)
		{
			ans = LLONG_MAX;
			for(int m = 1; m <= n; m++)
			{
				long long tmp = 0;
				tmp += m*(L2-R1);
				long long L2_old = L2;
				L2 = R1;
				long long x = (L2 - L1 + R2 - R1) * m;
				if(k <= x)
				{
					tmp += k;
				} else
				{
					tmp += x + (k-x)*2;
				}
				ans = min(ans, tmp);
				L2 = L2_old;
			}
			cout << ans << endl;
			continue;
		} else 
		{
			val -= n*(L2 - R1);
		}
		if(val >= k)
		{
			cout << 0 << endl;
			continue;
		}
		long long x = val + (L2 - L1 + R2 - R1) * n;
		if(k <= x)
		{
			ans += k - val;
		} else 
		{
			ans += x+(k-x)*2-val;
		}
		cout << ans << endl;
	}
}
