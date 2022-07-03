#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, start[MAXN]; // is each point a starting point?
pair<int, int> a[MAXN], ans[MAXN];
set<pair<int, int> > s;
map<pair<int, int>, int> id;
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
		s.insert(a[i]); // so we can find which things are contained by s in O(lg n) time
		id[a[i]] = i;
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			pair<int, int> b = {a[i].first + dx[j], a[i].second + dy[j]};
			if(!s.count(b))
			{
				start[i] = 1;
				ans[i] = b;
				break;
			}
		}
	}
	queue<pair<int, int> > q;
	for(int i = 0; i < n; i++)
	{
		if(start[i]) 
		{
			q.push(a[i]);
			s.erase(a[i]);
		}
	}
	// only need to bfs over points in the set that are bordered on all 4 sides by other points in the set
	while(!q.empty())
	{
		pair<int, int> b = q.front();
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			pair<int, int> c = {b.first + dx[i], b.second + dy[i]};
			if(s.count(c))
			{
				ans[id[c]] = ans[id[b]];
				q.push(c);
				s.erase(c);
			}
		}
	}

	for(int i = 0; i < n; i++)
	{
		cout << ans[i].first << " " << ans[i].second << endl; 
	}
}