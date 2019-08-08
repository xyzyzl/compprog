#include <bits/stdc++.h>

#define MAXN 1000005
using namespace std;

int n, x, c[105], d[MAXN];
int main()
{
	cin >> n >> x;
	for (int i = 0; i < n; i++)
		cin >> c[i];
	d[0] = 1;
	for (int j = 0; j < n; j++)
		for (int i = 1; i <= x; i++)
			if (i - c[j] >= 0)
				d[i] = (d[i] + d[i - c[j]]) % 1000000007;
	cout << d[x] << endl;
}

// TY FISHY