#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int n; cin >> n;
	if((long long)n*(n+1)/2 % 2) cout << "NO" << endl;
	else 
	{
		cout << "YES" << endl;
		vector<int> a, b;
		int si = 1;
		if(n%2)
		{
			a.push_back(1);
			a.push_back(2);
			b.push_back(3);
			si = 4;
		}
		for(; si <= n; si+=4)
		{
			a.push_back(si);
			b.push_back(si+1);
			b.push_back(si+2);
			a.push_back(si+3);
		}
		cout << a.size() << endl;
		for(int x : a) cout << x << ' ';
		cout << endl;
		cout << b.size() << endl;
		for(int x : b) cout << x << ' ';
		cout << endl;
	}
}