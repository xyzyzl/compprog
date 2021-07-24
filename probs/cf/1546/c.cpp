#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	map<int, int> m1, m2, p1, p2;
	for(int i = 0; i < n; i+=2)
	{
		m1[v[i]]++;
	}
	for(int i = 1; i < n; i+=2)
	{
		m2[v[i]]++;
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n; i+=2)
	{
		p1[v[i]]++;
	}
	for(int i = 1; i < n; i+=2)
	{
		p2[v[i]]++;
	}
	for(auto k : m1)
	{
		int i = k.first;
		if(m1[i] != p1[i])
		{
			cout << "NO" << endl;
			return;
		}
	}
	for(auto k : m2)
	{
		int i = k.first;
		if(m2[i] != p2[i])
		{
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main()
{
	int t; cin >> t; while(t--) solve();
}
