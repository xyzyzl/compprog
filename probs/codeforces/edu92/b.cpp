#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, k, z;
		cin >> n >> k >> z;
		vector<int> a(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		vector<int> pmax;
		for(int i = 1; i < n; i++) pmax.push_back(a[i] + a[i-1]);
		for(int i = 1; i < pmax.size(); i++) pmax[i] = max(pmax[i], pmax[i-1]);
		int ans = 0;
		for(int j = 0; j <= z; j++)
		{
			if(k - 2*j < 0) continue;
			int sm = a[0];
			for(int i = 1; i <= k - 2*j; i++) sm += a[i];
			sm += pmax[k - 2*j] * j;
			ans = max(ans, sm);
		}
		cout << ans << endl;
	}
}
