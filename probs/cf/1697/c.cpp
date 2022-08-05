#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q; cin >> q;
	while(q--)
	{
		int n; cin >> n;
		string s; cin >> s;
		string t; cin >> t;
		vector<char> st, tt;
		vector<int> si, ti;
		int fa=0,fb=0,fc=0;
		for(int i = 0; i < n; i++)
		{
			switch (s[i])
			{
			case 'a':
				fa++;
				break;
			case 'b':
				fb++;	
				break;
			default:
				fc++;
				break;
			}
		}
		for(int i = 0; i < n; i++)
		{
			switch (t[i])
			{
			case 'a':
				fa--;
				break;
			case 'b':
				fb--;	
				break;
			default:
				fc--;
				break;
			}
		}
		if(fa != 0 || fb != 0 || fc != 0)
		{
			goto no;
		}
		for(int i = 0; i < n; i++)
		{
			if(s[i] != 'b') st.push_back(s[i]);
			if(t[i] != 'b') tt.push_back(t[i]);
		}
		for(int i = 0; i < st.size(); i++)
		{
			if(st[i] != tt[i])
			{
				goto no;
			}
		}
		// a's can only move right, c's can only move left
		// so check the indices
		for(int i = 0; i < n; i++)
		{
			if(s[i] == 'a') si.push_back(i);
			if(t[i] == 'a') ti.push_back(i);
		}
		for(int i = 0; i < si.size(); i++)
		{
			if(si[i] > ti[i])
			{
				goto no;
			}
		}
		si.clear(); ti.clear();
		for(int i = n-1; i >= 0; i--)
		{
			if(s[i] == 'c') si.push_back(i);
			if(t[i] == 'c') ti.push_back(i);
		}
		for(int i = 0; i < si.size(); i++)
		{
			if(si[i] < ti[i])
			{
				goto no;
			}
		}
		cout << "YES" << endl;
		continue;
		no:
		cout << "NO" << endl;
	}
}