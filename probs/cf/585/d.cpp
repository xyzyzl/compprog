#include <bits/stdc++.h>

using namespace std;

const int MAXN = 25;

int n, mid;
// the added / removed approval from each hero for each action
int d[MAXN][3];
map<pair<int, int>, pair<int, int> > m;

// each recursion has the index we're at, the approvals we have per hero, and the steps we took to get here
void rec1(int i, int d0, int d1, int d2, int opt)
{
	if(i >= mid)
	{
		// find the largest happiness you can get for the first half
		if(m.count({d0-d1, d0-d2}))
		{
			if(m[{d0-d1, d0-d2}].first < d0) m[{d0-d1, d0-d2}] = {d0, opt};
		} else 
		{
			m[{d0-d1, d0-d2}] = {d0, opt};
		}
		return;
	}
	rec1(i+1, d0+d[i][0], d1+d[i][1], d2, opt*3);
	rec1(i+1, d0+d[i][0], d1, d2+d[i][2], opt*3+1);
	rec1(i+1, d0, d1+d[i][1], d2+d[i][2], opt*3+2);
}

const int INF = 1e9+7;
int maxs=-INF, lopt=0, ropt=0; // max sum and the optimal decision paths
void rec2(int i, int d0, int d1, int d2, int opt)
{
	if(i < mid)
	{
		if(m.find({d1-d0, d2-d0}) != m.end())
		{
			if(m[{d1-d0, d2-d0}].first + d0 > maxs)
			{
				maxs = m[{d1-d0, d2-d0}].first + d0;
				lopt = m[{d1-d0, d2-d0}].second;
				ropt = opt;
			}
		}
		return;
	}
	rec2(i-1, d0+d[i][0], d1+d[i][1], d2, opt*3);
	rec2(i-1, d0+d[i][0], d1, d2+d[i][2], opt*3+1);
	rec2(i-1, d0, d1+d[i][1], d2+d[i][2], opt*3+2);
}

string to[3] = {"LM", "LW", "MW"};
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> d[i][0] >> d[i][1] >> d[i][2];
	}
	mid = n/2;
	// 0 -> mid
	rec1(0, 0, 0, 0, 0);
	// n-1 -> mid
	rec2(n-1, 0, 0, 0, 0);
	if(maxs > -INF)
	{
		// retrace steps
		vector<int> r1, r2;
		for(int i = 0; i < n/2; i++)
		{
			r1.push_back(lopt % 3);
			lopt /= 3;
		}
		reverse(r1.begin(), r1.end());
		for(int x : r1)
		{
			cout << to[x] << endl;
		}
		for(int i = 0; i < n-n/2; i++)
		{
			cout << to[ropt % 3] << endl;
			ropt /= 3;
		}
	} else 
	{
		cout << "Impossible" << endl;
	}
}
