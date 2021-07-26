#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> x(n);
	for(int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	long long ans = 1;
	for(int i = 0; i < n; i++)
	{
		if(ans < x[i]) break;
		ans += x[i];
	}
	cout << ans << endl;
}
