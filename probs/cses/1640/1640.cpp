#include <bits/stdc++.h>

using namespace std;

int n;
pair<long long, int> a[200005];
long long x;
int main()
{
	cin >> n >> x;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i+1;
	}
	sort(a, a+n);
	int i = 0;
	int j = 1;
	while(j < n && a[i].first + a[j].first < x) j++;
	if(j == n) j--;
	while(i < j)
	{
		while(a[i].first + a[j].first > x) j--;
		if(a[i].first + a[j].first == x)
		{
			if(a[i].second == 0 || a[j].second == 0 || a[i].second == a[j].second)
			{
				cout << "IMPOSSIBLE" << endl;
			} else cout << min(a[i].second,a[j].second) << " " << max(a[i].second,a[j].second) << endl;
			return 0;
		}
		i++;
	}
	cout << "IMPOSSIBLE" << endl;
}