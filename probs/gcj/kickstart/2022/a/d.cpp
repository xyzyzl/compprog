#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int a, b; cin >> a >> b;
	int num = 0;
	for(int i = a; i <= b; i++)
	{
		int j = i;
		int sod = 0, prod = 1;
		while(j > 0)
		{
			sod += j % 10;
			prod *= j % 10;
			j /= 10;
		}
		if(prod % sod == 0) num++;
	}
	cout << num << endl;
}

int main()
{
	int t; cin >> t;
	for(int i = 1; i <= t; i++)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
}