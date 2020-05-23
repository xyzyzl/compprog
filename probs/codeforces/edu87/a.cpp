#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		if(a <= b)
		{
			cout << b << endl;
			continue;
		}
		if(c-d <= 0) cout << -1 << endl; // can't get any more good sleep time
		else cout << (long long) ceil((double)(a-b) / (double)(c-d))*(long long)c + (long long)b << endl;
	}
}
