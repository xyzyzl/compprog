#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> p(n);
	for(int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	sort(p.begin(), p.end());
	// median?
	long long k = 0;
	for(int i = 0; i < n; i++)
	{
		long long x = abs(p[i]-p[n/2]);
		k += x;
	}
	cout << k << endl;
}
