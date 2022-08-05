#include <bits/stdc++.h>

using namespace std;

pair<double, double> ans1, ans2;
double clo(int n, vector<pair<double,double>>& v)
{
	set<pair<double, double>> s;
	double bd = INFINITY;
	int j = 0;
	for(int i = 0; i < n; i++)
	{
		while(v[i].first - v[j].first >= bd && j < i)
		{
			s.erase({v[j].second, v[j].first});
			j++;
		}

		auto it1 = s.lower_bound({v[j].second - bd, INFINITY});
		auto it2 = s.upper_bound({v[j].second + bd, INFINITY});
		// cerr << it1->first << " " << it2->first << endl;
		for(auto it = it1; it != it2; it++)
		{
			double dx = v[i].first - it->second;
			double dy = v[i].second - it->first;
			if(sqrt(dx*dx+dy*dy) < bd)
			{
				bd = sqrt(dx*dx+dy*dy);
				ans1 = {v[i].first, v[i].second};
				ans2 = {it->second, it->first};
			}
		}
		s.insert({v[i].second, v[i].first});
	}
	return bd;
}

int main()
{
	int n;
	cin >> n;
	vector<pair<double, double>> v(n);
	for(int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	// cerr << clo(n,v) << endl;
	cout << clo(n,v) << endl;
}