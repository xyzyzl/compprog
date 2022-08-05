#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

int n, half, v[MAXN];
bool check(int x)
{
	// ret = # of differences that are < x
	int ret = 0;
	for(int i = 0; i < n; i++)
	{
		// lb gives the first pos in the array v that is greater than v[i] + x
		ret += lower_bound(v+i, v+n, v[i]+x) - (v+i) - 1;
	}
	return ret >= half;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	// use this when they're too big of an a-hole to give # of test cases up front
	while(cin >> n)
	{
		for(int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		sort(v, v+n);
		// they will need C(C-1)/2/2 = C(C-1)/4
		half = n*(n-1)/2;
		half = (half+1)/2; // floor division -> send 3
		// we can binary search on whether or not the median works
		int lo = -1, hi = v[n-1]-v[0]+1;
		while(lo+1 < hi)
		{
			int mid = (lo+hi)/2;
			if(check(mid))
			{
				hi = mid;
			} else 
			{
				lo = mid;
			}
		}
		cout << hi << endl;
		// cerr << check(0, n, v) << endl;
	}
}