/*input
aybabtu
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s; cin >> s;
	int n = s.length();
	// basically just an implementation of Manacher's
	vector<int> d1(n), d2(n);
	int ans = 0, mx = -1;
	for(int i = 0, l = 0, r = -1; i < n; i++)
	{
		int k = (i > r) ? 1 : min(d1[l+r-i], r-i+1);
		while(0 <= i - k && i + k < n && s[i-k] == s[i+k]) ++k;
		d1[i] = k--;
		if(i+k > r)
		{
			l = i-k;
			r = i+k;
		}
		if(2*d1[i] - 1 > mx) ans = i-k, mx = 2*d1[i]-1;
	}
	for(int i = 0, l = 0, r = -1; i < n; i++)
	{
		int k = (i > r) ? 0 : min(d2[l+r-i+1], r-i+1);
		while(0 <= i - k - 1 && i + k < n && s[i-k-1] == s[i+k]) ++k;
		d2[i] = k--;
		if(i+k > r)
		{
			l = i-k-1;
			r = i+k;
		}
		if(2*d2[i] > mx) ans = i-k-1, mx = 2*d2[i];
	}

	cout << s.substr(ans, mx) << endl;
}