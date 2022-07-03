#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n; cin >> n;
	string s; cin >> s;
	vector<int> par(n);
	vector<int> nxt(n);
	vector<int> vis(n);
	// find all cycles
	for(int i = 0; i < n; i++)
	{
		int k; cin >> k;
		par[k-1] = i;
		nxt[i] = k-1;
	}
	vector<vector<char> > v;
	for(int i = 0; i < n; i++)
	{
		if(vis[i]) continue;
		vis[i] = 1;
		v.push_back({s[i]});
		int x = nxt[i];
		while(x != i)
		{
			vis[x] = 1;
			v.back().push_back(s[x]);
			x = nxt[x];
		}
	}
	vector<string> sv;
	for(vector<char> q : v)
	{
		string str(q.begin(), q.end());
		sv.push_back(str);
		// cerr << str << endl;
	}
	long long ret = 1;
	for(string s : sv)
	{
		long long ans = s.length();
		string t = s;
		for(int i = 0; i < s.length(); i++)
		{
			t = t[s.length()-1] + t.substr(0, s.length()-1);
			if(t == s)
			{
				ans = i+1;
				break;
			}
		}
		// cerr << ans << endl;
		ret = lcm(ans, ret);
	}
	cout << ret << endl;
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		solve();
	}
}
