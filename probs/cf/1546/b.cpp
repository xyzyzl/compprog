#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n, m; cin >> n >> m;
	vector<string> V(n);
	for(int i = 0; i < n; i++)
	{
		cin >> V[i];
	}
	vector<string> U(n);
	for(int i = 0; i < n-1; i++)
	{
		cin >> U[i];
	}
	vector<char> v;
	for(int i = 0; i < m; i++)
	{
		map<char, int> fq;
		for(int j = 0; j < n; j++)
		{
			fq[V[j][i]]++;
		}
		for(int j = 0; j < n-1; j++)
		{
			fq[U[j][i]]++;
		}
		for(char c = 'a'; c <= 'z'; c++) if(fq[c]%2) v.push_back(c); 
	}
	for(int i = 0; i < m; i++) cout << v[i];
	cout << endl;
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
