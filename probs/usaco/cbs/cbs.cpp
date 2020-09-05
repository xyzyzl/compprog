#include <bits/stdc++.h>

using namespace std;

int k,n,pr[15][50005],ps[15][50005],ct[15][50005];
int main()
{
	cin >> k >> n;
	for(int i = 0; i < k; i++)
	{
		for(int j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			if(c == '(')
			{
				ps[i][j] = 1;
			} else
			{
				ps[i][j] = -1;
			}
		}
		for(int j = 1; j < n; j++)
		{
			ps[i][j] = ps[i][j-1] + ps[i][j];
		}
		stack<int> mono, mon2;
		mono.push(0);
		pr[i][0] = -1;
		for(int j = 1; j < n; j++)
		{
			while(!mono.empty() && ps[i][mono.top()] >= ps[i][j]) mono.pop();
			while(!mon2.empty() && ps[i][mon2.top()] >  ps[i][j]) mon2.pop();
			if(mono.empty())
			{
				pr[i][j] = -1;
			} else
			{
				pr[i][j] = mono.top();
			}
			mono.push(j);
		}
		for(int j = 0; j < n; j++) cerr << pr[i][j] << " ";
		cerr << endl;
	}
}
