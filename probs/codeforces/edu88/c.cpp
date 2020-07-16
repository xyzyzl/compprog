#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int h, c, t;
		cin >> h >> c >> t;
		if(h+c-2*t >= 0)
		{
			cout << 2 << endl;
		} else 
		{
			int k = (h-t)/(2*t-h-c);
			int a = (2*k+3)*((2*k+1)*t -   k * (h+c) - h);
			int b = (2*k+1)*((2*k+3)*t - (k+1)*(h+c) - h);
			if(abs(a) > abs(b)) k++;

			cout << 2*k + 1 << endl;
		}
	}
}

