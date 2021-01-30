#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int MAXN = 100005;
using pii = pair<int, int>;
using vi = vector<int>;
#define f first
#define s second
#define pb push_back
#define ins insert

int N, K;
ll M;
pii ab[MAXN];
vi V[MAXN], Vm[MAXN];
set<int> Vt[MAXN];
int swp[MAXN], swp2[MAXN];
int main()
{
	cin >> N >> K >> M;
	for(int i = 0; i < N; i++)
	{
		Vt[i].ins(i);
		swp[i] = i;
	}
	for(int i = 0; i < K; i++)
	{
		cin >> ab[i].f >> ab[i].s;
		ab[i].f--; ab[i].s--;
	}
	for(int i = 0; i < K; i++)
	{
		V[swp[ab[i].f]].pb(ab[i].s);
		V[swp[ab[i].s]].pb(ab[i].f);
		swap(swp[ab[i].f], swp[ab[i].s]);
	}
	for(int i = 0; i < N; i++) swp2[i] = i;
	int L = M%K;
	for(int i = 0; i < L; i++)
	{
		Vm[swp2[ab[i].f]].pb(swp2[ab[i].s]);
		Vm[swp2[ab[i].s]].pb(swp2[ab[i].f]);
		swap(swp2[ab[i].f], swp2[ab[i].s]);
	}
	for(int i = 0; i < N; i++) swp2[i] = i;
	ll X = M/K;
	for(int i = 0; i < X; i++)
	{
		for(int i = 0; i < N; i++)
		{
			for(int j : V[i])
			{
				Vt[swp2[i]].ins(j);
			}
		}
		for(int i = 0; i < N; i++)
		{
			swp2[i] = swp[swp2[i]];
		}
	}
	for(int i = 0; i < N; i++)
	{
		for(int j : Vm[i]) Vt[swp2[i]].ins(j);
	}
	for(int i = 0; i < N; i++)
	{
		cout << Vt[i].size() << endl;
	}
}
