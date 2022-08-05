#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		vector<int> a(n);
		map<int, int> last;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];	
			last[a[i]] = i;
		}
		int ans = 0;
		for(int i = 0; i < n; i++)
		{
			if(last[a[i]] != i)
			{
				ans = i+1;
			}
		}
		cout << ans << endl;
	}
}