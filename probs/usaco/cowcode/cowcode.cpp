#include <bits/stdc++.h>

using namespace std;

string s;
long long n, m;
int main()
{
	freopen("cowcode.in", "r", stdin);
	freopen("cowcode.out", "w", stdout);
	cin >> s >> n;
	m = s.length();
	while(m * 2 < n) m *= 2;
	while(n > s.length())
	{
		// ------------------------------------------------ //
		// remap n to first half but remember cyclic shift. //
		// m+1 goes to m, and the rest go to 1...m-1.       //
		// ------------------------------------------------ //
		if(n == m+1) n = m;
		else n -= m+1;

		// decrease m to be suitable for the next step
		// sums to lg n operations over all indices
		while(m >= n) m /= 2;
	}
	// O(lg n) time in total
	cout << s[n-1] << endl; // guaranteed to be under n now
}