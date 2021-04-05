#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n; cin >> n;
	map<int, int> fq;
	for(int i = 0; i < n; i++)
	{
		int a; cin >> a;
		fq[a]++;
	}
	priority_queue<pair<int, int> > flist;
	for(auto e : fq)
	{
		flist.push({e.second, e.first});
	}
	int siz = n;
	while(flist.size() >= 2)
	{
		pair<int, int> a = flist.top();
		flist.pop();
		pair<int, int> b = flist.top();
		flist.pop();
		a.first--;
		b.first--;
		siz -= 2;
		if(a.first)
		{
			flist.push(a);
		}
		if(b.first)
		{
			flist.push(b);
		}
	}
	cout << siz << endl;
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
