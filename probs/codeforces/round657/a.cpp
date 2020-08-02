#include <bits/stdc++.h>

using namespace std;

const string FIXED = "abacaba";
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		string t;
		cin >> t;
		bool found = 0;
		for(int x = 0; x < n-6; x++)
		{
			string s = t;
			bool good = 1;
			for(int i = 0; i < 7; i++)
			{
				if(s[i+x] == FIXED[i] || s[i+x] == '?')
					continue;
				good = 0;
				break;
			}
			if(!good) continue;
			for(int i = 0; i < 7; i++)
			{
				if(s[i+x] == '?')
				{
					s[i+x] = FIXED[i];
				}
			}
			for(int i = 0; i < n; i++)
			{
				if(s[i] == '?') s[i] = 'd';
			}
			int occ = 0;
			for(int i = 0; i < n-6; i++)
			{
				good = 1;
				for(int j = 0; j < 7; j++)
				{
					if(s[i+j] == FIXED[j] || s[i+j] == '?')
						continue;
					good = 0;
					break;
				}
				if(!good) continue;
				occ++;
			}
			if(occ == 1)
			{
				cout << "Yes" << endl;
				cout << s << endl;
				found = 1;
				break;
			}
		}
		if(!found) cout << "No" << endl;
	}
}
