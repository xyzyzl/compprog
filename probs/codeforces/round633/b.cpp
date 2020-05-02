#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; i++) cin >> v[i];
		sort(v.begin(), v.end());
		vector<int> v2;
		for(int i = 0; i < n/2 + (n % 2); i++)
		{
			v2.push_back(v[i]);
			if(i != n-i-1)
			{
				v2.push_back(v[n-i-1]);
			}
		}
		reverse(v2.begin(), v2.end());
		for(int x : v2) cout << x << " ";
		cout << endl;
	}
}
