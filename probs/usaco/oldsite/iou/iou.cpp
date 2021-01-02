#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	// amount that bessie is owed / owes
	vector<int> owe(n);
	for(int i = 0; i < n; i++)
	{
		 cin >> owe[i];
	}
	int last = -1; // the first cow that Bessie owes
	int cash = 0, debt = 0;
	int ret = 0;
	for(int i = 0; i < n; i++)
	{
		ret++;
		// if someone owes Bessie money
		if(owe[i] >= 0)
		{
			// add to current cash amount
			cash += owe[i];
			// pay off some debt and add walking distance
			if(debt > 0 && cash >= debt)
			{
				cash -= debt;
				debt = 0;
				ret += 2*(i-last);
			}
		} else // Bessie owes someone money
		{
			// pay off some amount with current cash
			if(debt == 0 && cash >= abs(owe[i]))
			{
				cash -= abs(owe[i]);
				continue;
			}
			// if there's no debt for this cow but we can't pay it right now we
			// come back to it later. this is also the first cow that hasn't been
			// paid off, or the last cow that we have to go to to pay off debt
			else if(debt == 0) last = i;
			debt += abs(owe[i]);
		}
	}
	cout << ret << endl;
}
