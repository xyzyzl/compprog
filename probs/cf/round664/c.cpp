#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(m);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	for(int res = 0; res < 512; res++)
	{
		bool can = 1;
		for(int i = 0; i < n; i++)
		{
			bool is = 0;
			for(int j = 0; j < m; j++)
			{
				if(((a[i] & b[j]) | res) == res) is = 1;
			}
			can &= is;
		}
		if(can) 
		{
			cout << res << endl;
			return 0;
		}
	}
}
