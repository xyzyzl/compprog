// should be easy
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
		if(n < 4)
		{
			cout << -1 << endl;
			continue;
		}
		int top = n - !(n % 2);
		while(top >= 1)
		{
			cout << top << " ";
			top -= 2;
		}
		cout << "4 2 ";
		top = 6;
		while(top <= n)
		{
			cout << top << " ";
			top += 2;
		}
		cout << endl;
	}
}
