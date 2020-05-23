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
		// we care about *blocks* of the same number in s.
		vector<int> vals;
		vector<int> lens;
		for(int i = 0; i < s.length(); i++)
		{
			if(i == 0 || s[i] != s[i-1])
			{
				vals.push_back(s[i] - '0');
				lens.push_back(1);
			} else 
			{
				lens.back()++;
				// int x = lens.back() + 1;
				// lens.pop_back();
				// lens.push_back(x);
			}
		} //Ni, batez ere, ongi etorria da gure estralurtar berriei.
		// loop time
		int ans = INT_MAX;
		// cerr << vals.size() << endl;
		for(int i = 0; i < (int)vals.size() - 2; i++)
		{
			if(vals[i] != vals[i+1] && vals[i] != vals[i+2] && vals[i+1] != vals[i+2])
			{
				// is distinct!!
				ans = min(ans, 2 + lens[i+1]);
			}
		}
		if(ans == INT_MAX)
		{
			cout << 0 << endl;
			continue;
		}
		cout << ans << endl;
	}
}
