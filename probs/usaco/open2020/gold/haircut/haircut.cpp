#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int N, A[100005];
ll BIT[200005];
ll inv_gt[100005]; // all inversions with both sides >= i

void upd(int ind, int val)
{
	while(ind <= N+1) 
	{
		BIT[ind] += val;
		ind += ind&-ind;
	}
}

ll sum(int ind)
{
	ll ret = 0;
	while(ind > 0)
	{
		ret += BIT[ind];
		ind -= ind&-ind;
	}
	return ret;
}

ll find_inv()
{
	ll ret = 0;
	for(int i = 0; i < N; i++)
	{
		//A[i] != 0
		inv_gt[i] = sum(N+1)-sum(A[i]+1);
		ret += inv_gt[i];
		upd(A[i]+1, 1);
	}
	return ret;
}

int main()
{
	freopen("haircut.in", "r", stdin);
	freopen("haircut.out", "w", stdout);
	cin >> N;
	vector<vector<ll> > V(N+1);
	for(int i = 0; i < N; i++)
	{
		cin >> A[i];
		V[A[i]].push_back(i);
	}
	ll tot = find_inv();
	vector<ll> k(N);
	for(int i = N-1; i >= 0; i--)
	{
		for(int x : V[i])
		{
			tot -= inv_gt[x];
		}
		k[i] = tot;
	}
	for(int i = 0; i < N; i++) cout << k[i] << endl;
}