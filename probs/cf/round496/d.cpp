#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s; cin >> s; int n = s.length();
	int n1 = 0, n2 = 0, ans = 0;
	for(int i = 0; i < n; i++)
	{
		int x = s[i] - '0';
		bool can = 0;
		if(x%3==0) can = 1;
		if(x%3==1)
		{
			if(n2 >= 1) can = 1;
			if(n1 >= 2) can = 1;
			n1++;
		}
		if(x%3==2)
		{
			if(n1 >= 1) can = 1;
			if(n2 >= 2) can = 1;
			n2++;
		} 
		if(can) 
		{
			ans++;
			n1=n2=0;
		}
	}
	cout << ans << endl;
}