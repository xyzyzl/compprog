#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
	inline bool ends_with(std::string const &value, std::string const &ending)
	{
		if (ending.size() > value.size())
			return false;
		return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
	}
	string shortestSuperstring(vector<string> &A)
	{
		int n = A.size();
		vector<vector<int>> dp(4100, vector<int>(15));
		vector<vector<int>> pp(4100, vector<int>(15));
		vector<vector<int>> over(15, vector<int>(15));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int m = min(A[i].length(), A[j].length());
				for (int k = m; k >= 0; k--)
				{
					if (ends_with(A[i], A[j].substr(0, k)))
					{
						over[i][j] = k;
						cerr << over[i][j] << " ";
						break;
					}
				}
			}
			cerr << endl;
		}
		for (int msk = 0; msk < (1 << n); msk++)
		{
			for (int i = 0; i < n; i++)
				pp[msk][i] = -1;
			for (int i = 0; i < n; i++)
				if (msk & (1 << i)) // find dp[mask][i]
				{
					int pmsk = (msk ^ (1 << i)); // get rid of this one
					if (pmsk == 0)
						continue;
					for (int j = 0; j < n; j++)
						if (pmsk & (1 << j) && j != i)
						{
							int v = dp[pmsk][j] + over[j][i];
							if (v > dp[msk][i])
							{
								dp[msk][i] = v;
								pp[msk][i] = j;
							}
						}
				}
		}
		int m_ind = 0;
		for (int i = 1; i < n; i++)
		{
			if (dp[(1 << n) - 1][i] > dp[(1 << n) - 1][m_ind])
				m_ind = i;
		}
		vector<int> pm;
		int msk = (1 << n) - 1;
		vector<int> vis(n);
		while (m_ind != -1)
		{
			vis[m_ind] = 1;
			pm.push_back(m_ind);
			int x = pp[msk][m_ind];
			msk ^= (1 << m_ind);
			m_ind = x;
		}
		reverse(pm.begin(), pm.end());
		for (int i = 0; i < n; i++)
			if (!vis[i])
			{
				cerr << A[i] << endl;
				pm.push_back(i);
			}
		string ans = A[pm[0]];
		for (int i = 1; i < n; i++)
		{
			int clip = over[pm[i - 1]][pm[i]];
			ans += A[pm[i]].substr(clip);
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	vector<string> A = {"catg", "ctaagt", "gcta", "ttca", "atgatc"};
	cout << sol.shortestSuperstring(A) << endl;
}