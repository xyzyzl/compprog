#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	vector<vector<int> > grid(n, vector<int>(m));
	for(int i = x; i > 0; i--)
	{
		cout << i << " " << y << endl;
	}
	for(int i = x+1; i <= n; i++)
	{
		cout << i << " " << y << endl;
	}
	int j = 1;
	while(true)
	{
		if(j==y) j++;
		if(j > m) break;
		for(int i = n; i > 0; i--)
		{
			cout << i << " " << j << endl;
		}
		j++;
		if(j==y) j++;
		if(j > m) break;
		for(int i = 1; i <= n; i++)
		{
			cout << i << " " << j << endl;
		}
		j++;
	}
}
