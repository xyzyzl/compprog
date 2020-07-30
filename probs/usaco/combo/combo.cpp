// Solution By Albert Ye
// AlphaStar 2020 Summer Camp: CC31AB
// Problem: nov13-combo
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int f[3], m[3];
	cin >> f[0] >> f[1] >> f[2];
	cin >> m[0] >> m[1] >> m[2];
	int ct = 0;
	// iterate for all combinations in the lock and find if it's close enough manually
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			for(int k = 1; k <= n; k++)
			{
				// check if close enough to f
				if((abs(i-f[0]) <= 2 || abs(i-f[0]) >= n-2) && (abs(j-f[1]) <= 2 || abs(j-f[1]) >= n-2) && (abs(k-f[2]) <= 2 || abs(k-f[2]) >= n-2))
					ct++;	
				// check if close enough to m
				else if((abs(i-m[0]) <= 2 || abs(i-m[0]) >= n-2) && (abs(j-m[1]) <= 2 || abs(j-m[1]) >= n-2) && (abs(k-m[2]) <= 2 || abs(k-m[2]) >= n-2))
					ct++;
			}
		}
	}
	// O(N^3) is ok
	cout << ct << endl;
}
