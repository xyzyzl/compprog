#include <bits/stdc++.h>

using namespace std;

int f[200005][26];
void solve()
{
	int n,k; cin >> n >> k;
	string s; cin >> s;
	for(int i = 0; i < n; i++) for(int j = 0; j < 26; j++) f[i][j]=0;
	for(int i = 0; i < n; i++)
	{
		f[i%k][s[i]-'a']++;
	}
	int ret = 0;
	for(int i = 0; i < k/2; i++)
	{
		int mx = 0;
		for(int j = 0; j < 26; j++)
		{
			int a = 0;
			a += f[i][j];
			a += f[k-1-i][j];
			mx = max(mx, a);
		}
		ret += 2*(n/k) - mx;
	}
	if(k%2)
	{
		int mx = 0;
		for(int j = 0; j < 26; j++)
		{
			int a = 0;
			a += f[k/2][j];
			mx = max(mx, a);
		}
		ret += (n/k)-mx;
	}
	cout << ret << endl;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
}
