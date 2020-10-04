#include <bits/stdc++.h>

#define int long long 
using namespace std;

signed main()
{
	int n;
	cin >> n;
	set<int> s;
	s.insert(0);
	int sm = 0;
	int A = 0;
	for(int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		sm += k;
		if(s.count(sm))
		{
			// already has sm
			s.clear();
			s.insert(0);
			sm = k;
			s.insert(sm);
			A++; // increment answer
		}
		s.insert(sm);
	}
	cout << A << endl;
}