#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,a,b;
		string s = "";
		cin >> n >> a >> b;
		int ind = 0;
		while(a > b)
		{
			s += 'a';
			a--;
			ind++;
		}
		for(int i = 0; i < b; i++)
		{
			ind++;
			s += ('a' + i);
		}
		while(ind < n)
		{
			s += s[ind-b];
			ind++;
		}
		cout << s << endl;
	}
}