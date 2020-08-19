#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		if(n % 2 == 0)
		{
			cout << n/2 << " " << n/2 << endl;
		} else 
		{
			int a, b = 0;
			for(a = 2 ; a * a <= n; a++)
			{
				if(n % a == 0)
				{
					b = a;
					break;
				}
			}
			if(!b)
			{
				b = n;
			}
			// (n/a) * some shit
			cout << (n/b) << " " << (n-n/b) << endl;
		}
	}
}
