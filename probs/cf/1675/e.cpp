#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n, k; cin >> n >> k;
		string s; cin >> s;
		map<char, char> ma;
		for(char c = 'a'; c <= 'z'; c++)
		{
			ma[c] = c;
		}
		int x = min(k, s[0]-'a');
		k -= x;
		char maxc = 'a';
		for(char c = s[0]-x; c <= s[0]; c++)
		{
			ma[c] = s[0]-x;
		}
		if(s[0] - x == 'a')
		{
			maxc = s[0];
		}
		if(k)
		{
			for(int i = 1; i < n; i++)
			{
				if(k == 0) break;
				if(s[i] < maxc) continue;
				int d = s[i] - maxc;
				if(k >= d)
				{
					k -= d;
					for(char c = maxc+1; c <= s[i]; c++)
					{
						ma[c] = 'a';
					}
					maxc = s[i];
				} else 
				{
					// still optimal to reduce this character than to skip it over
					for(char c = s[i] - k; c <= s[i]; c++)
					{
						ma[c] = s[i] - k;
					}
					k = 0;
				}
			}
		}
		for(int i = 0; i < n; i++) cout << ma[s[i]];
		cout << endl;
	}
}
