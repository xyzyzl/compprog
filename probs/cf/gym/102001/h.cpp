#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100005;

int N, K, a[MAXN], bit[2*MAXN];

int sum(int ind)
{
	int ret = 0;
	while(ind >= 0)
	{
		ret += bit[ind];
		ind -= (ind&-ind);
	}
	return ret;
}

vector<pair<int, pair<int, int> > > V;
int main()
{
	cin >> N >> K;
	for(int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < K; i++)
	{
		int a, b, c; cin >> a >> b >> c;
	}
}