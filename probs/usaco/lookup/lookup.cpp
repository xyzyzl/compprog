// Solution by Albert Ye
// AlphaStar 2020 Summer Camp: CC31AB
// Problem: mar09-lookup
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	// stores heights, indices
	stack<pair<int, int> > st;
	// the answer for each cow
	vector<int> ans(n+1);
	for(int i = 1; i <= n; i++)
	{
		int x;
		// height of current cow
		cin >> x;
		// if the last cow in stack is shorter than the current cow
		// the answer for that cow is the index of the current cow
		// and remove the cow so that future cows don't consider it
		// this ensures that the answer is correct
		while(!st.empty() && st.top().first < x)
		{
			ans[st.top().second] = i;
			st.pop();
		}
		// add the current cow
		st.push(make_pair(x,i));
	}
	for(int i = 1; i <= n; i++)
	{
		cout << ans[i] << endl;
	}
}
