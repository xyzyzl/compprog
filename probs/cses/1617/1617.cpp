#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;
const int MOD = 1000000007;

int n, p2[MAXN];
int main()
{
	cin >> n;
	p2[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		p2[i] = (p2[i-1] * 2) % MOD;
	}
	cout << p2[n] << endl;
}
