#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	long long x; cin >> x;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	vector<long long> sl, sr;
	for(int i = 0; i < (1 << (n/2)); i++)
	{
		long long s = 0;
		for(int j = 0; j < n/2; j++)
		{
			if(i & (1 << j)) s += v[j];	
		}
		sl.push_back(s);
	}
	reverse(v.begin(), v.end());
	for(int i = 0; i < (1 << ((n+1)/2)); i++)
	{
		long long s = 0;
		for(int j = 0; j < (n+1)/2; j++)
		{
			if(i & (1 << j)) s += v[j];	
		}
		sr.push_back(s);
	}
	sort(sl.begin(), sl.end());
	sort(sr.begin(), sr.end());
	long long ans = 0;
	for(long long i : sl)
	{
		int a = lower_bound(sr.begin(), sr.end(), x-i)-sr.begin();
		int b = upper_bound(sr.begin(), sr.end(), x-i)-sr.begin();
		ans += b-a; 
	}
	cout << ans << endl;
}