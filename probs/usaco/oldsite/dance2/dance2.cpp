#include <bits/stdc++.h>

using namespace std;

int n, m, delta;
int main()
{
	cin >> n;
	for(int iter = 0; iter < n; iter++)
	{
		delta = 0;
		cin >> m;
		string s; cin >> s;
		for(int i = 0; i < m; i++)
		{
			if(s[i] == '>') delta++;
			else delta--;
			if(delta < 0)
			{
				goto end;
			}
		}
		if(delta != 0)
		{
			goto end;
		}
		cout << "legal" << endl;
		continue;
end:
		cout << "illegal" << endl;
	}
}
