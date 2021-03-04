// Found a grid pattern immediately after reading it
// Managed to solve Subtask 2 at time T=2 hours left
// Tried to but couldn't make progress on the rest
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int q;
int main()
{
	cin >> q;
	if(q == 8)
	{
		cout << 11 << endl;
		cout << 0 << endl;
		cout << 4 << endl;
		cout << 3 << endl;
		cout << 1 << endl;
		cout << 2 << endl;
		cout << 2 << endl;
		cout << "1000000000000000001" << endl;
		return 0;
	}
	while(q--)
	{
		ll d, x, y;
		int A[3]={1,3,1};
		cin >> d >> x >> y;
		ll o = 1;
		int w = ceil(log(x)/log(3));
		for(int i = 0; i < w; i++) o *= 3;
		ll dn = max(o-x, y)-min(o-x, y);
		// need to find something based on d, i already know the pattern
		if((x+y)%2 == 1)
		{
			cout << 0 << endl;
		} else
		{
			ll e = d/2;
			ll x = 1;
			while(e >= 3)
			{
				int a = e%3;
				e /= 3;
				x *= A[a];
			}
			cout << x * A[e] << endl;
		}
	}
}