#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> owe(n);
	for(int i = 0; i < n; i++)
	{
		 cin >> owe[i];
	}
	int last = -1;
	int cash = 0, debt = 0;
	int ret = 0;
	for(int i = 0; i < n; i++)
	{
		ret++;
		if(owe[i] >= 0)
		{
			cash += owe[i];
			if(debt > 0 && cash >= debt)
			{
				cash -= debt;
				debt = 0;
				ret += 2*(i-last);
			}
		} else
		{
			if(debt == 0 && cash >= abs(owe[i]))
			{
				cash -= abs(owe[i]);
				continue;
			}
			else if(debt == 0) last = i;
			debt += abs(owe[i]);
		}
	}
	cout << ret << endl;
}
