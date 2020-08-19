#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int l, r;
		cin >> l >> r;
		if(r/l == 1) 
		{
			cout << -1 << " " << -1 << endl;
		} else 
		{
			cout << l << " " << 2*l << endl;
		}
	}
}
