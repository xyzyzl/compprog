#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n; cin >> n;
	int p = 0;
	int k = 1;
	while(k <= n)
	{
		k *= 5;
		++p;
	}
	// cerr << p << endl;
	k = 1;
	long long ans = 0;
	for(int i = 1; i < p; i++)
	{
		k *= 5;
		ans += (n / k);
	}
	cout << ans << endl;
}
