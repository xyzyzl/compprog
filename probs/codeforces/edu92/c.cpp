#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		int n = s.length();
		// iterate through digits
		int ans = n-2;
		for(char a = '0'; a <= '9'; a++) for(char b = a; b <= '9'; b++)
		{
			char c[2] = { a, b };
			int cur = -1, rem = 0, len = 0;
			for(int i = 0; i < n; i++)
			{
				if(cur == -1)
				{
					if(s[i] == c[0])
					{
						cur = 1;
						len++;
					}
					else if (s[i] == c[1])
					{
						cur = 0;
						len++;
					}
					else rem++;
				} else 
				{
					if(s[i] == c[cur])
					{
						cur = (cur+1)%2;
						len++;
					}
					else rem++;
				}
			}
			if(a != b && len%2) rem++;
			ans = min(ans, rem);
		}
		cout << ans << endl;
	}
}
