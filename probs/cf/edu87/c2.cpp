#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592653589

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << setprecision(10) << fixed << cos(PI/(4.0*n))/sin(PI/(2.0*n)) << endl;
	}
}