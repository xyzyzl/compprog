// dunce cap
// can't solve this stupid problem because i have no way to debug things correctly
// finding the algo was easy enough, but implementation took far too long because i didn't actually read my code from start to finish and find what i actually
// did wrong :(((((
#include <bits/stdc++.h>

using namespace std;

#define MAXN 200005

int n, m;
int w[MAXN], a[MAXN];
bool gone[MAXN], vis[MAXN];
vector<int> ppl[MAXN];
pair<int, int> xy[MAXN];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> w[i];
		ppl[i].clear();
	}
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		--x; --y;
		xy[i] = make_pair(x, y);
		a[xy[i].first]++;
		a[xy[i].second]++;
		ppl[x].push_back(i);
		ppl[y].push_back(i);
	}
	/*
	for(int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
	for(int i = 0; i < n; i++) cout << w[i] << " ";
	cout << endl;
	*/
	for(int i = 0; i < n; i++)
	{
		if(a[i]) pq.push(make_pair(max(0, a[i] - w[i]), i));
		else gone[i] = 1;
	}
	vector<int> ret;
	while(pq.size())
	{
		// there is still something there
		pair<int, int> tp = pq.top();
		// cout << tp.first << " " << tp.second << endl;
		pq.pop();
		if(tp.first != max(0, a[tp.second]-w[tp.second])) continue;
		if(tp.first > 0) // not enough friends for this food
		{
			cout << "DEAD" << endl;
			return 0;
		}
		int ind = tp.second;
		vector<int> rem;
		for(int q : ppl[ind])
		{
			if(vis[q]) continue;
			vis[q] = 1;
			ret.push_back(q);
			int at = xy[q].first;
			int ot = xy[q].second;
			if(xy[q].first != ind)
			{
				int tmp = at;
				at = ot;
				ot = tmp;
			}
			// cerr << gone[0] << endl;
			if(!gone[ot])
			{
				rem.push_back(ot);
			}
		}
		// cerr << rem.size() << endl;
		sort(rem.begin(), rem.end());
		for(int i = 0; i < rem.size(); i++)
		{
			a[rem[i]]--;
			if((i == rem.size() - 1 || rem[i] != rem[i+1]) && a[rem[i]])
			{
				// cerr << a[rem[i]] - w[rem[i]] << " " << rem[i] << endl;
				// check if the thing is empty
				if(max(0, a[rem[i]] - w[rem[i]]) == 0) gone[rem[i]] = 1;
				pq.push(make_pair(max(0, a[rem[i]] - w[rem[i]]), rem[i]));
				// if(max(0, a[rem[i]] - w[rem[i]]) == 1) cout << "no" << endl;
			}
		}
	}
	cout << "ALIVE" << endl;
	reverse(ret.begin(), ret.end());
	for(int q : ret)
	{
		cout << q+1 << " ";
	}
	cout << endl;
}
