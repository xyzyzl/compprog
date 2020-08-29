#include <bits/stdc++.h>

using namespace std;

int q,x;
struct cmp
{
	bool operator()(pair<int, int> a, pair<int, int> b) const
	{
		if(a.second==b.second)return a.first<b.first;
		return a.second<b.second;
	}
};
int main()
{
	cin >> q >> x;
	vector<int> rc(x);
	set<pair<int,int> > s;
	for(int i = 0; i < x; i++) s.insert({0,i});
	for(int i = 0; i < q; i++)
	{
		int y;
		cin >> y;
		s.erase(make_pair(rc[y%x],y%x));
		rc[y%x]++;
		s.insert(make_pair(rc[y%x],y%x));
		cout << (s.begin()->first) * x + (s.begin()->second) << endl;
	}
}
