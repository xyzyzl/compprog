#include <bits/stdc++.h>

using namespace std;

int m,t,r,ans;
int w[305];
map<int, int> ma;
int main()
{
	cin >> m >> t >> r;
	for(int i = 0; i < m; i++) cin >> w[i];
	for(int i = 0; i < m; i++)
	{
		int ct = 0;
		for(int j = w[i]-1; j >= w[i]-t; j--)
		{
			if(ma[j]) ct++;
		}
		for(int j = w[i]-1; j >= w[i]-t; j--)
		{
			if(ct >= r) break;
			if(!ma[j])
			{
				ma[j]=1;
				ans++;
				ct++;
			}
		}
		if(ct < r)
		{
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ans << endl;
}