#include <bits/stdc++.h>

using namespace std;

void zalgo(string s)
{
	int n = s.size();
	vector<int> z(n, 0);
	int x=0,y=0;
	for(int i = 1; i < n; i++) 
	{
		z[i] = max(0, min(z[i-x], y-i+1));
		while(i+z[i] < n && s[z[i]] == s[i+z[i]])
		{
			x = i;
			y = i + z[i];
			z[i]++;
		}
		if(z[i] + i == n) cout << i << ' ';
	}
	cout << n << endl;
}

int main()
{
	string s; cin >> s;
	zalgo(s);
}
