#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n; cin >> n;
	string s; cin >> s;
	vector<int> psum(n);
	psum[0] = (s[0] == '+' ? 1 : -1);
	for(int i = 1; i < n; i++)
	{
		psum[i] = psum[i-1] + (s[i] == '+' ? 1 : -1);
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			int dif = (j ? psum[i] - psum[j-1] : psum[i]);
			if(dif <= 0 && dif % 3 == 0)
			{
				ans++;
			}
		}
	}
	cout << ans << endl;
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}