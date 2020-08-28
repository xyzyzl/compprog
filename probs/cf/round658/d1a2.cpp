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
		vector<int> v(n+1);
		for(int i = 0; i < n; i++)
		{
			char c;
			cin >> c;
			c -= '0';
			v[i] = c;
		}
		v[n] = 0;
		vector<int> top;
		for(int i = 1; i <= n; i++)
		{
			if(v[i-1] != v[i]) top.push_back(i);
		}
		vector<int> u(n+1);
		for(int i = 0; i < n; i++)
		{
			char c;
			cin >> c;
			c -= '0';
			u[i] = c;
		}
		u[n] = 0;
		for(int i = n; i > 0; i--)
		{
			if(u[i] != u[i-1]) top.push_back(i);
		}
		cout << top.size() << " ";
		for(int x : top) cout << x << " ";
		cout << endl;
	}
}
