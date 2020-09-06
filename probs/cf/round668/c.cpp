#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<int> v(n);
		int c1 = 0, c0 = 0;
		for(int i = 0; i < n; i++)
		{
			if(s[i] == '?') continue;
			int o = (s[i] == '1') ? 1 : -1;
			if(v[i%k] != o && v[i%k] != 0) 
			{
				goto here;
			}
			v[i%k] = o;
		}
		for(int i = 0; i < k; i++)
		{
			if(v[i] > 0) c1++;
			else if(v[i] < 0) c0++;
		}
		if(c1 > k/2 || c0 > k/2) goto here;
		cout << "YES" << endl;
		continue;
here:
		cout << "NO" << endl;
	}
}
