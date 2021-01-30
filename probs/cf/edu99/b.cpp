#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n = 1, s = 0;
		int x; cin >> x;
		while(s < x) s += (n++);
		if(x == s-1) cout << n << endl;
		else cout << n-1 << endl;
	}
}
