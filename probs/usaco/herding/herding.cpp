#include <bits/stdc++.h>

using namespace std;

int n, a[100005];
int main()
{
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a+n);
	int ans = 0;
	if((a[n-2] - a[0] == n-2) && (a[n-1]-a[n-2] > 2)) ans++;
	if((a[n-1] - a[1] == n-2) && (a[1]-a[0] > 2))     ans++;
	int tmp = INT_MAX;
	for(int i = 0; i < n; i++)
	{
		int j = i;
		while(j < n && a[j] <= a[i]+n-1) j++;
		tmp = min(tmp, n-(j-i));
	}
	cout << ans+tmp << endl;
	ans = 0;
	for(int i = 1; i < n; i++)
	{
		ans += a[i] - a[i-1] - 1;
	}
	ans -= min(a[1] - a[0], a[n-1] - a[n-2]) - 1;
	cout << ans << endl;
}
