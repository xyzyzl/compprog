#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		s += 'a';
		int n = s.length();
		int pre = 0;
		vector<int> v;
		for(int i = 1; i < n; i++)
		{
			if(s[i] != s[i-1])
			{
				if(s[i-1] == '1') 
				{
					v.push_back(i-pre);
				}
				pre = i;
			}
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		int ans = 0;
		for(int i = 0; i < v.size(); i += 2)
		{
			ans += v[i];
		}
		cout << ans << endl;
	}
}
