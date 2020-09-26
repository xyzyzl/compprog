// the main idea for this question is DP. let dp[i] be the shortest distance to get to
// the start of board i. we need to thus find the largest amount skipped.

// one naive O(N^2) way to do this is by simply looking at all previous boards and finding the
// best one. however, N^2 only gets a third of the test cases. instead, we search for 
// 
#include <bits/stdc++.h>

using namespace std;

int n, p, dp[100005]; // dp[i] = shortest distance to get to i
vector<pair<pair<int, int>, pair<int, int> > > v;
#define f first
#define s second
map<int, int> pre; // every valid point

int 
main()
{
	freopen("boards.in", "r", stdin);
	freopen("boards.out", "w", stdout);
	cin >> n >> p;
	for(int i = 0; i < p; i++) 
	{
		pair<int, int> a,b;
		cin >> a.f >> a.s >> b.f >> b.s;
		v.push_back(make_pair(a, make_pair(i, 0)));
		v.push_back(make_pair(b, make_pair(i, 1)));
	}
	sort(v.begin(), v.end());
	pre[0] = 0;
	for(auto x : v)
	{
		if(x.s.s)
		{
			// add to pre
			int dst = dp[x.s.f] - x.f.f - x.f.s;
			auto k = prev(pre.upper_bound(x.f.s));
			if(k->s <= dst) continue; // can already save equal distance; don't need this value
			k++;
			while(k != pre.end() && k->s > dst) pre.erase(k++); // remove if can save shorter distance.
			pre[x.f.s] = dst;
		} else
		{
			dp[x.s.f] = x.f.f + x.f.s + prev(pre.upper_bound(x.f.s))->s; // take longest distance saved and remove from x.f.f+x.f.s.
		}
	}
	cout << (2*n + pre.rbegin()->s) << endl;
}