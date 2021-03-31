#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;
	
int n;
pair<int, int> p[MAXN];

void solve()
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> p[i].first;
	for(int i = 0; i < n; i++) cin >> p[i].second;
	sort(p, p+n);
	int cr = 1, cc = 1;
	int tot = 0;
	for(int i = 0; i < n; i++)
	{
		int nr = p[i].first, nc = p[i].second;		
		// find the distance from (1, 1) to (r2-r1+1, c2-c1+1)
		if(nr-cr == nc-cc)
		{
			tot += ((cr+cc)%2?0:nr-cr);
		} else 
		{
			nr -= cr-1;
			nc -= cc-1;
			if((cr+cc)%2==0) tot += (nr-nc)/2;
			else             tot += (nr-nc+1)/2;
			nr += cr-1;
			nc += cc-1;
		}
		cr = nr;
		cc = nc;
	}
	cout << tot << endl;
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}