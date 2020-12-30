#include <bits/stdc++.h>

using namespace std;

int n, a, b, mat[1005][1005];
int main()
{
	cin >> n >> a >> b;
	if(a == 1 && b == 1)
	{
		if(n == 2 || n == 3)
		{
			cout << "NO" << endl;
			return 0;
		} else
		{
			cout << "YES" << endl;
			for(int i = 1; i < n; i++)
			{
				mat[i][i-1] = mat[i-1][i] = 1;
			}
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cout << mat[i][j];
			}
			cout << endl;
		}
	}
	else if(a == 1 || b == 1)
	{
		cout << "YES" << endl;
		if(a > 1)
		{
			for(int i = 1; i <= n-a; i++)
			{
				mat[i-1][i] = mat[i][i-1] = 1;
			}
		} else
		{
			// b > 1
			for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++)
			{
				mat[i][j] = mat[j][i] = 1;
			}
			for(int i = 1; i <= n-b; i++)
			{
				mat[i-1][i] = mat[i][i-1] = 0;
			}
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cout << mat[i][j];
			}
			cout << endl;
		}
	} else
	{
		cout << "NO" << endl;
	}
}