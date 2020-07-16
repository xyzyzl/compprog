#include <bits/stdc++.h>

using namespace std;

long long kadane(vector<int> v)
{
	int n = v.size();
	long long best = 0, mx = 0;
	for(int i = 0; i < n; i++)
	{
		mx += v[i];
		if(best < mx) best = mx;
		if(mx   <  0) mx   =  0;
	}
	return best;
}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		long long ret = 0;
		for(int i = 0; i < n; i++ )
		{
			cin >> v[i];
			if(i % 2 == 0) ret += v[i];
		}
		vector<int> a1, a2;
		for(int i = 0; i < n-1; i+=2) 
		{
			a1.push_back(v[i+1] - v[i]);
		}
		for(int i = 1; i < n-1; i+=2)
		{
			a2.push_back(v[i] - v[1+i]);
		}
		long long ans1 = kadane(a1);
		long long ans2 = kadane(a2);
		cout << (ret + max(ans1, ans2)) << endl;
	}
}

