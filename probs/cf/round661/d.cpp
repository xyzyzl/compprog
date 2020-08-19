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
		string s;
		cin >> s;
		vector<int> v(n), v0, v1;
		for(int i = 0; i < n; i++)
		{
			if(s[i] == '0')
			{
				if(v1.empty())
				{
					v[i] = v0.size() + v1.size();
					v0.push_back(v0.size() + v1.size());
				} else
				{
					int x = v1.back();
					v1.pop_back();
					v0.push_back(x);
					v[i] = x;
				}
			} else 
			{
				if(v0.empty())
				{
					v[i] = v0.size() + v1.size();
					v1.push_back(v0.size() + v1.size());
				} else
				{
					int x = v0.back();
					v0.pop_back();
					v1.push_back(x);
					v[i] = x;
				}
			}
		}
		cout << v0.size() + v1.size() << endl;
		for(int x : v) cout << 1+x << " ";
		cout << endl;
	}
}
