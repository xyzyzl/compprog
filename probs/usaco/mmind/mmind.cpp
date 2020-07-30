// Solution by: Albert Ye
// AlphaStar 2020 Summer Camp: CC31AB
// Problem: mar10-mmind
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<string, pair<int, int> > > v;
	for(int i = 0; i < n; i++)
	{
		string num;
		int c, w;
		cin >> num >> c >> w;
		v.push_back(make_pair(num, make_pair(c, w)));
	}
	// brute force for all numbers
	for(int num = 1000; num <= 9999; num++)
	{
		bool works = 1;
		// check if it matches the description for all hints
		for(int x = 0; x < n; x++)
		{
			// indices that have already been matched in answer and hint, respectively
			vector<bool> m1(n), m2(n);
			string tmp = to_string(num);
			int sm = 0, df = 0;
			for(int i = 0; i < 4; i++)
			{
				if(tmp[i] == v[x].first[i])
				{
					sm++;
					// found a match for both strings at i
					m1[i] = m2[i] = 1;
				}
			}
			for(int i = 0; i < 4; i++)
			{
				if(!m1[i])
				{
					for(int j = 0; j < 4; j++)
					{
						// check if answer is equal to hint at different indices
						if(!(m2[j]) && tmp[i] == v[x].first[j])
						{
							df++;
							m1[i] = m2[j] = 1;
						}
					}
				}
			}
			// check if the amount same/different positions is the same as described
			// if not, this number doesn't work
			if(sm != v[x].second.first || df != v[x].second.second)
			{
				works = 0;
				break;
			}
		}
		if(works)
		{
			// we've found an answer
			cout << num << endl;
			return 0;
		}
	}
	cout << "NONE" << endl;
	// O(900N) solution. ok
}
