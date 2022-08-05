#include <bits/stdc++.h>

using namespace std;

int numSubarraysWithSum(vector<int> &nums, int goal)
{
	vector<int> psum(nums.size() + 5);
	psum[0] = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		psum[i + 1] = psum[i] + nums[i];
	}
	map<int, int> ct; // number of occurrences of psum at i
	int ans = 0;
	for (int i = 0; i <= nums.size(); i++)
	{
		ans += ct[psum[i]];
		ct[psum[i] + goal]++;
	}
	return ans;
}

int main()
{
	int n, goal; cin >> n >> goal;
	vector<int> nums; for(int i = 0; i < n; i++)
	{
		char t; cin >> t;
		int k = t-'0';
		nums.push_back(k);
	}
	cout << numSubarraysWithSum(nums, goal) << endl;
}
