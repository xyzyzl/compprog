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
		for(int i = 0; i < n; i++)
			cin >> v[i];
		if(v[0] + v[1] <= v[n-1]) cout << 1 << " " << 2 << " " << n << endl;
		else cout << -1 << endl;
	}
}
