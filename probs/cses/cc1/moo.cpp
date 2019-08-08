#include <bits/stdc++.h>

#define MAXN 105
#define MOD 1000000007

using namespace std;

int n, x, c[MAXN], d[1000005];
int main()
{
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	d[0] = 1;
	for (int i = 1; i <= x; i++)
	{
		for (int j = 0; j < n; j++)
			if (i - c[j] >= 0)
			{
				d[i] = (d[i] + d[i - c[j]]) % MOD;
			}
	}
	cout << d[x] << endl;
}