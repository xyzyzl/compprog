#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		vector<int> frq(n+1);
		int kurwa = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> v[i];
			if(frq[v[i]] == 0) kurwa++;
			frq[v[i]]++;
		}
		if(n==1)
		{
			cout << 0 << endl;
			continue;
		}
		sort(frq.begin(), frq.end());
		int mac = frq.back();
		if(kurwa == mac) mac--;
		int y =min(kurwa, mac);
		cout << y << endl;
	}
}