#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500005;

int n, k, Z[MAXN];
string s;

void find_Z(string &s)
{
	for(int i = 1, l = 0, r = 0; i < n; i++)
	{
		if(i <= r) Z[i] = min(r-i+1, Z[i-l]);
		while(i + Z[i] < n && s[Z[i]] == s[i+Z[i]]) ++Z[i];
		if(i + Z[i] - 1 > r) l = i, r = i+Z[i]-1;
	}
}

int main()
{
	cin >> n >> k >> s;
	int lp = 1;
	Z[0] = -1;
	find_Z(s);
	int L = 1;
	for(int i = 1; i < n; i++) 
	{
		if(s[i] > s[i % L])
		{
			// our job here is done
			for(int i = 0; i < k; i++) cout << s[i % L];
			cout << endl;
			return 0;
		}
		if(s[i] < s[i % L]) 
		{
			L = i+1; continue; // automatically consider the next value
		}
		// now the only case is that s[i] = s[i % L]
		int rem = i-L+1;
		if(rem == L)
		{
			// literally just a second repeat of the current, no need to keep
			// the current over current + current
			L = i+1;
			continue;
		}
		// basically using the z function here
		// if the longest common prefix of rem is less than what can
		// create another iteration of s[:L]
		if(Z[rem] < L-rem)
		{
			if(L+rem+Z[rem] >= k) L = i+1;
			else if(s[rem+Z[rem]] > s[Z[rem]]) L = i+1;
		} else if(Z[L-rem] < rem)
		{
			// same thing here
			if(2 * L + Z[L-rem] >= k) L = i+1;
			else if(s[L-rem+Z[L-rem]] < s[Z[L-rem]]) L = i+1;
		} else L = i+1; // if neither of these constraints is true we can auto promote L
	}
	for(int i = 0; i < k; i++) cout << s[i % L]; cout << endl;
}
