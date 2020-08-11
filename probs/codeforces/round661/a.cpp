#include <bits/stdc++.h>

using namespace std;

int t;
int main()
{
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; i++) cin >> v[i];
		sort(v.begin(), v.end());
		bool good = 1;
		for(int i = 1; i < n; i++)
		{
			if(v[i] - v[i-1] > 1) good = 0;
		}
		cout << (good ? "YES" : "NO") << endl;
	}
}
