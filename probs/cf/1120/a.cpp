#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500005;

// a is as defined, b is frequencies in sequence, c is current frequency for subarr
int m,k,n,s,a[MAXN],b[MAXN],c[MAXN],dif,d;
vector<int> loc; // locations we have to remove

// check if there are enough wreaths if we remove a bunch
// r is the right end of the segment, l is the left end.
bool check(int l, int r)
{
	// cerr << l << " " << r << endl;
	int z = l/k+1; // # of segments before l 
	if(r-dif+1 <= z*k)
	{
		// only need to push the answer once
		for(int i = (z-1)*k+1; i <= l && loc.size() < dif; i++) loc.push_back(i);
		for(int i = l; i <= r && loc.size() < dif; i++)
		{
			if(c[a[i]]-- > b[a[i]]) loc.push_back(i+1);
		}
		return 1;
	}
	return 0;
}

int main()
{
	cin >> m >> k >> n >> s;
	dif = m-n*k;
	for(int i = 0; i < m; i++) cin >> a[i];
	for(int i = 0; i < s; i++)
	{
		int ty; cin >> ty;
		b[ty]++;
	}
	// 2 pointer
	int j = -1;
	for(int i = 0; i < m; i++)
	{
		while(d < s && ++j < m) if(++c[a[j]] <= b[a[j]]) ++d;
		if(d==s && check(i,j))
		{
			cout << loc.size() << endl;
			for(int x : loc) cout << x << ' ';
			return 0;
		}
		if(c[a[i]]-- <= b[a[i]]) --d;
	}
	cout << -1 << endl;
}