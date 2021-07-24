#include <bits/stdc++.h>

using namespace std;

int n;
string s;
map<int, int> ma;
int main()
{
	cin >> s;
	n = s.length();
	for(int i = 0; i < n; i++)
	{
		ma[s[i]]++;
	}
	int od=0;
	int one = -1;
	for(char c = 'A'; c <= 'Z'; c++)
	{
		if(ma[c]%2) 
		{
			od++;
			one=c;
		}
	}
	if(od > 1) cout << "NO SOLUTION" << endl;
	else 
	{
		vector<char> t;
		int w = 0;
		for(char c = 'A'; c <= 'Z'; c++)
		{
			if(ma[c] && !(ma[c]%2)) 
			{
				for(int i = 0; i < ma[c]/2; i++)
					t.push_back(c);
			} else if(ma[c]%2)
			{
				w = ma[c];
			}
		}
		for(int i = 0; i < t.size(); i++)
			cout << (char)t[i];
		if(one != -1) for(int i = 0; i < w; i++) cout << (char)one;
		for(int i = t.size()-1; i >= 0; i--)
			cout << (char)t[i];
	}
}
