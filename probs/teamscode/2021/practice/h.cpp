#include <bits/stdc++.h>

using namespace std;

int n;
int X[1005][1005], D[1005][1005];
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			cin >> X[i][j];
			D[i][j] = X[i][j];
		}
	}
	for(int i = n-2; i >= 0; i--)
	{
		for(int j = 0; j <= i; j++)
		{
			int k = X[i][j] + max(D[i+1][j], D[i+1][j+1]);
			D[i][j] = k;
		}
	}
	cout << D[0][0] << endl;
}
