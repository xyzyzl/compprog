#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

typedef pair<int, int> pii;
#define F first
#define S second

#define bitinc(x) (x&-x)

bool comp(pii x, pii y)
{
	int p = min(x.F, x.S);
	int q = min(y.F, y.S);
	return p < q;
}

int n;
long long bit[2*MAXN];
vector<int> inds[MAXN][2];
vector<pii> ind;

long long sum(int ind)
{
	++ind;
	int sm = 0;
	while(ind > 0)
	{
		sm += bit[ind];
		ind -= bitinc(ind);
	}
	return sm;
}
void upd(int ind, int val)
{
	++ind;
	while(ind <= n)
	{
		bit[ind] += val;
		ind += bitinc(ind);
	}
}

long long count_swaps(vector<int> s) {
	for(int i = 0; i < 2*MAXN; i++) bit[i] = 0;
	n = s.size();
	for(int i = 0; i < n; i++)
	{
		if(s[i] < 0)
		{
			inds[-s[i]][0].push_back(i);
		} else 
		{
			inds[s[i]][1].push_back(i);
		}
	}
	for(int i = 1; i <= n/2; i++)
	{
		for(int j = 0; j < inds[i][0].size(); j++)
		{
			ind.push_back({inds[i][0][j], inds[i][1][j]});
		}
	}
	sort(ind.begin(), ind.end(), comp);
	for(int i = 0; i < n; i++) upd(i, 1);
	long long ret = 0;
	for(int i = 0; i < ind.size(); i++)
	{
		upd(ind[i].F, -1);
		upd(ind[i].S, -1);
		int x = ind[i].F, y = ind[i].S;
		if(ind[i].F > ind[i].S)
		{
			++ret;
			swap(x,y);
		}
		ret += sum(y) - sum(x-1);
	}
	return ret;
}

int main()
{
	cout << count_swaps({-2, 2, 2, -2, -2, 2}) << endl;
}
