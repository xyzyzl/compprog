#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<vector<int> > ps(1001, vector<int>(1001, 0));
	for(int i = 0; i < n; i++)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		ps[x1][y1]++;
		ps[x1][y2]--;
		ps[x2][y1]--;
		ps[x2][y2]++;
	}
	for(int i = 0; i <= 1000; i++)
	{
		for(int j = 0; j <= 1000; j++)
		{
			if(i)    ps[i][j] += ps[i-1][j];
			if(j)    ps[i][j] += ps[i][j-1];
			if(i&&j) ps[i][j] -= ps[i-1][j-1];
		}
	}
	int ct_k = 0;
	for(int i = 0; i <= 1000; i++)
	{
		for(int j = 0; j <= 1000; j++)
		{
			if(ps[i][j] == k) ct_k++;
		}
	}
	cout << ct_k << endl;
}
