// Solution by Albert Ye
// AlphaStar 2020 Summer Camp: CC31AB
// Problem: train1.3-calfflac
#include <bits/stdc++.h>

using namespace std;


int main()
{
	string s, s_strip;
	vector<int> mp; // maps s_strip indices to s indices
	int ln = 0;
	while(!cin.eof())
	{
		if(ln) s+='\n'; // output needs newlines
		++ln;
		string t;
		getline(cin, t); // input rest of line
		s += t;
	}
	for(int i = 0; i < s.length(); i++)
	{
		if('a' <= tolower(s[i]) && tolower(s[i]) <= 'z')
		{
			s_strip += tolower(s[i]);
			mp.push_back(i);
		}
	}
	// find palindromes in s_strip
	// brute force over all positions
	// max. palindrome and first and last indices
	int ans = 0, x = 0, y = 0;
	for(int i = 0; i < s.length(); i++)
	{
		// odd length permutation
		{
			// left and right indices and size of string
			int lo = i;
			int hi = i;
			int sz = 1;
			while(lo >= 0 && hi < s_strip.length() && s_strip[lo] == s_strip[hi])
			{
				lo--;
				hi++;
				sz += 2;
			}
			// current lo and hi are not part of the palindrome, need to adjust
			lo++;
			hi--;
			sz -= 2;
			// maximize answer
			if(sz > ans)
			{
				x = lo;
				y = hi;
				ans = sz;
			}
		}
		// even length permutation
		if(i > 1)
		{
			// left and right indices and size of string
			int lo = i-1;
			int hi = i;
			int sz = 2;
			while(lo >= 0 && hi < s_strip.length() && s_strip[lo] == s_strip[hi])
			{
				lo--;
				hi++;
				sz += 2;
			}
			// current lo and hi are not part of the palindrome, need to adjust
			lo++;
			hi--;
			sz -= 2;
			// maximize answer
			if(sz > ans)
			{
				x = lo;
				y = hi;
				ans = sz;
			}
		}
	}
	// print answer. remember to map x, y -> mp[x], mp[y]
	cout << ans << endl;
	cout << s.substr(mp[x], mp[y] - mp[x] + 1) << endl;
}

