#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> pts[1005];
vector<pair<int, pair<int,int> > > v;


int p[2005 * 2005], sz[2005 * 2005];

int find_set(int i)
{
	return (p[i] == i) ? i : (p[i] = find_set(p[i]));
}

bool union_set(int i, int j)
{
	int x = find_set(i);
	int y = find_set(j);
	if (x == y)
		return false;
	p[x] = p[y] = x;
	sz[x] += sz[y];
	return true;
}

void init()
{
	for(int i = 0; i < N; i++) p[i] = i;
	for(int i = 0; i < N; i++) sz[i] = 1;
}

int main()
{
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> pts[i].first >> pts[i].second;
	}
	for(int i = 0; i < N; i++) for(int j = i+1; j < N; j++)
	{
		v.push_back(make_pair((pts[i].first-pts[j].first)*(pts[i].first-pts[j].first)+(pts[i].second-pts[j].second)*(pts[i].second-pts[j].second), make_pair(i,j)));
		v.push_back(make_pair((pts[i].first-pts[j].first)*(pts[i].first-pts[j].first)+(pts[i].second-pts[j].second)*(pts[i].second-pts[j].second), make_pair(j,i)));
	}
	sort(v.begin(),v.end());
	init();
	int mx = 0;
	int ct = N-1;
	for(pair<int, pair<int, int> > P : v)
	{
		if(union_set(P.second.first, P.second.second))
		{
			mx = P.first;
			if(--ct == 0) break;
		}
	}
	cout << mx << endl;
}
