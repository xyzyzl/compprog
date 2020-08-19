#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int l, r;
		long long m;
		cin >> l >> r >> m;
		for(long long a = l; a <= r; a++)
		{
			long long b, c;
			long long n = (m+r-l);
			n /= a;
			if(m-r+l <= n*a && n*a <= m+r-l)
			{
				int diff = m-n*a;
				if(diff < 0)
				{
					b = l;
					c = l-diff;
				} else
				{
					b = r;
					c = r-diff;
				}
				cout << a << " " << b << " " << c << endl;
				break;
			}
		}
	}
}
				
