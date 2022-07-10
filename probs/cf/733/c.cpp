#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;

int n, k, a[MAXN], b[MAXN];
int ans[MAXN][2];
int main()
{
	cin >> n; for(int i = 0; i < n; i++) cin >> a[i];
	cin >> k; for(int i = 0; i < k; i++) cin >> b[i];
	int p = 0, q, inc = 0, steps = 0;
	while(p < k)
	{
		if(a[0] == b[p])
		{
			n--;
			for(int i = 0; i < n; i++) a[i] = a[i+1];
			p++, inc++;
			continue;
		}
		int sum = a[0], mx = -1, mxn;
		for(int i = 1; i < n && sum < b[p]; sum += a[i], i++)
		{
			if(a[i] != a[i-1] && mx < a[i] + a[i-1])
			{
				mx = a[i] + a[i-1], mxn = i;
			}
		}
		// cerr << sum << " " << b[p] << endl;
		// cerr << mx << " " << mxn << endl;
		if(mx == -1	|| sum != b[p])
		{
			cout << "NO" << endl;
			return 0;
		}
		if(a[mxn] > a[mxn-1])
		{
			ans[++steps][0] = mxn + 1 + inc, ans[steps][1] = 0;
		} else 
		{
			cerr << p << endl;
			ans[++steps][0] = mxn + inc, ans[steps][1] = 1;
		}
		a[mxn-1] += a[mxn];
		n--;
		for(int i = mxn; i < n; i++) a[i] = a[i+1];
	}
	if(n >= 1)
	{
		cout << "NO" << endl;
	} else 
	{
		cout << "YES" << endl;
		for(int i = 1; i <= steps; i++)
		{
			cout << ans[i][0] << " " << (ans[i][1] ? "R" : "L") << endl;
		}
	}
}