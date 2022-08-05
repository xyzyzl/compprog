#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n, m; cin >> n >> m;
		vector<int> a(n);
		vector<int> b(m);
		stack<int> s;
		for(int i = 0; i < n; i++)
		{
			char k; cin >> k;
			a[i] = k-'0';
		}
		for(int i = n-1; i >= 0; i--) s.push(a[i]);
		for(int i = 0; i < m; i++)
		{
			char k; cin >> k;
			b[i] = k-'0';
		}
		for(int i = 0; i < n-m; i++)
		{
			int u = s.top();
			s.pop();
			int v = s.top();
			s.pop();
			if(v == u)
			{
				s.push(v);
			} else 
			{
				// decide whether to make it 0 or 1
				if(b[0] == 0) 
				{
					s.push(0);
				} else s.push(1);
			}
		}
		vector<int> c;
		while(s.size())
		{
			c.push_back(s.top());
			s.pop();
		}
		if(c.size() != m)
		{
			cout << "NO" << endl;
			continue;
		}
		bool yes = 1;
		for(int i = 0; i < c.size(); i++)
		{
			if(c[i] != b[i]) yes = 0;
		}
		cout << (yes ? "YES" : "NO") << endl;
	}
}