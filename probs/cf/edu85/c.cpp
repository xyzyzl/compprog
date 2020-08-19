#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<long long> a(n);
		vector<long long> b(n);
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			cin >> b[i];
		}
		vector<long long> c(n);
		long long csum = 0;
		for(int i = 0; i < n; i++)
		{
			c[i] = max(0ll, a[i] - b[(i-1+n)%n]);
			csum += c[i];
		}
		long long best = LLONG_MAX;
		for(int i = 0; i < n; i++)
		{
			best = min(best, csum - c[i] + a[i]);
		}
		cout << best << endl;
	}
}
