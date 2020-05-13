#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

int n, k;
int b[MAXN];
void solve()
{
	cin >> n >> k;
	bool good = 0;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		b[i] = (a < k ? 0 : (a == k ? 1 : 2));
		if(b[i] == 1) good = 1;
	}
	if(!good)
	{
		cout << "no" << endl;
		return;
	} else if(n == 1)
	{
		cout << "yes" << endl;
		return;
	}
	good = 0;
	for(int x = 1; x <= 2; x++)
	{
		for(int i = 0; i < n-x; i++)
		{
			if(b[i] > 0 && b[i+x] > 0) good = 1;
		}
	}
	if(!good)
	{
		cout << "no" << endl;
		return;
	}
	cout << "yes" << endl;
}

int main()
{
	int t;
	cin >> t;
	while(t--) solve();
}
