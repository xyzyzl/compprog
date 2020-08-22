#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long ans = 0;
		int x1,y1,z1,x2,y2,z2;
		cin>>x1>>y1>>z1>>x2>>y2>>z2;
		int rem = min(y2, z1);
		z1 -= rem;
		y2 -= rem;
		ans += 2*rem;
		if(z2+x2 >= z1)
		{
			int k = min(z2, z1);
			z2 -= k;
			z1 -= k;
			x2 -= z1;
		}
		if(y2+x2 >= y1)
		{
			int k = min(y2, y1);
			y2 -= k;
			y1 -= k;
			x2 -= y1;
		}
		z2 -= min(z2, x1);
		ans -= 2*(min(y1, z2));
		cout << ans << endl;
	}
}
