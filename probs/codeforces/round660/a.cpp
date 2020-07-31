#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		if(n <= 30) cout << "NO" << endl;
		else 
		{
			cout << "YES" << endl;
			if(n == 36)
			{
				cout << 5 << " " << 6 << " " << 10 << " " << 15 << endl;
			} else if (n == 40)
			{
				cout << 5 << " " << 6 << " " << 14 << " " << 15 << endl;
			} else if (n == 44)
			{
				cout << 6 << " " << 7 << " " << 10 << " " << 21 << endl;
			}
			else cout << 6 << " " << 10 << " " << 14 << " " << (n-30) << endl;
		}
	}
}
