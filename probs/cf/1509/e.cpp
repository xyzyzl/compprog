#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
	int n; ll k; cin >> n >> k;
	if(n <= 62 && (1ll << n-1) < k)
	{
		cout << -1 << endl; return;
	}
	--k; 
	vector<int> v(n+1), r(n+1);
	int a = n-2;
	while(a >= 0)
	{
		int x = k%2;
		v[a--] = x;
		k /= 2;
	}
	/*
	for(int i = 0; i < n; i++) cerr << v[i] << " ";
	cerr << endl;
	*/
	int pre = -1;
	int q = 1;
	for(int i = 0; i < n; i++)
	{
		if(v[i] == 0)
		{
			for(int j = i; j > pre; j--)
			{
				r[j]=q++;
			}
			pre=i;
		}
	}
	for(int i = 0; i < n; i++) cout << r[i] << " ";
	cout << endl;
}

int main()
{
	int t; cin >> t; while(t--) solve();
}
