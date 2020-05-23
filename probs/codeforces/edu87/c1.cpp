#include <bits/stdc++.h>

using namespace std;

const long double PI = 3.141592653589;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << setprecision(11) << fixed << 1/tan(2 * PI / (4 * n)) << endl;
	}
}
