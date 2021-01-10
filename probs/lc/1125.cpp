#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
	vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
	{
		int n = req_skills.size(), m = people.size();
		map<string, int> maaap; int ct = 0; for(string s : req_skills) maaap[s] = ct++;
		vector<int> pmsk; for(int i = 0; i < m; i++)
		{
			int msk = 0;
			for(string s : people[i]) msk += (1 << maaap[s]);
			pmsk.push_back(msk);
		}
		vector<pair<int, vector<int> > > dp((1 << n));
		dp[0] = make_pair(0, vector<int>(1, -1));
		for(int i = 1; i < (1 << n); i++)
		{
			dp[i] = make_pair(1000, vector<int>(1, -1));
		}
		for(int i = 0; i < m; i++)
		{
			for(int msk = 0; msk < (1 << n); msk++)
			{
				if(dp[msk|pmsk[i]].first > 1 + dp[msk].first)
				{
					dp[msk|pmsk[i]].first = 1+ dp[msk].first;
					if(dp[msk].second[0] == -1)
					{
						// hasn't been touched yet
						dp[msk|pmsk[i]].second = {i};
					} else
					{
						dp[msk|pmsk[i]].second = dp[msk].second;
						dp[msk|pmsk[i]].second.push_back(i);
					}
					
				}
			}
		}
		return dp[(1 << n)-1].second;
	}
};

int main()
{
	Solution sol;
	vector<string> req_skills = {"java","nodejs","reactjs"};
	vector<vector<string> > people = {{"java"},{"nodejs"},{"nodejs","reactjs"}};
	vector<int> v = sol.smallestSufficientTeam(req_skills, people);
	for(int x : v)
	{
		cout << x << " ";
	}
	cout << endl;
}