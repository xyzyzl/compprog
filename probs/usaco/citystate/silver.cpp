// Solution by: Albert Ye
// AlphaStar 2020 Summer Camp: CC31AB
// Problem: dec16-citystate
#include <bits/stdc++.h>

using namespace std;

int n; // number of cities
map<string, int> frq; // frequency of (first two letters of city)-(state) combo
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		// city, state
		string ci, st;
		cin >> ci >> st;
		// only first two letters of city matter
		ci = ci.substr(0, 2);
		if(ci != st)
		{
			// first two letters of city followed by state
			frq[ci + st]++;
		}
	}
	// number of pairs that satisfy
	int ct = 0;
	for(auto a : frq)
	{
		string x = a.first;
		// check the inverse ordering; see if it exists
		// if so add all possible reordered cities
		if(frq[x.substr(2,2) + x.substr(0,2)] > 0) ct += frq[x] * frq[x.substr(2,2) + x.substr(0,2)];
	}
	// double count
	cout << (ct / 2) << endl;
}
