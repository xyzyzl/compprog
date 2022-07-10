#include <bits/stdc++.h>

using namespace std;
typedef pair<pair<int, int>,pair<int, int>> que;
#define f first
#define s second

int n;
set<int> co;
map<int, int> cc;
que A[100005];
// instead of keeping an integer in the BIT, we keep a tuple
map<int, int> bit[200005];

// takes the sum at a specific value T and time ind.
int sum(int ind, int T)
{
	int sm = 0;
	while(ind > 0)
	{
		sm += bit[ind][T];
		ind -= ind&-ind;
	}
	return sm;
}

void upd(int ind, int val, int T)
{
	while(ind <= n)
	{
		bit[ind][T] += val;
		ind += ind&-ind;
	}
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int a, t, x;
		cin >> a >> t >> x;
		A[i] = {{t, i}, {x, a}};
		co.insert(t);
	}
	int ind = 0;
	for(int x : co)
	{
		cc[x] = ++ind;
	}
	// standardize the time
	for(int i = 0; i < n; i++) A[i].f.f = cc[A[i].f.f];
	// still has to be processed in the right order, cannot sort A
	for(int i = 0; i < n; i++)
	{
		if(A[i].s.s == 1) upd(A[i].f.f, 1, A[i].s.f);
		else if(A[i].s.s == 2) upd(A[i].f.f, -1, A[i].s.f);
		else
		{
			int X = sum(A[i].f.f, A[i].s.f);
			cout << X << endl;
		}
	}
}