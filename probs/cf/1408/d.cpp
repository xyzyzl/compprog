#include <bits/stdc++.h>

using namespace std;

int n, m, A[1000005];
typedef pair<int, int> pii;
#define f first
#define s second
pii R[2005], S[2005];
int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> R[i].f >> R[i].s;
	}
	for(int i = 0; i < m; i++) 
	{
		cin >> S[i].f >> S[i].s;
	}
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
	{
		if(S[j].f - R[i].f < 0) continue; // no need
		// make sure searchlight j cannot see criminal i
		A[S[j].f - R[i].f] = max(A[S[j].f - R[i].f], S[j].s - R[i].s + 1);
	}
	for(int i = 1000001; i >= 0; i--)
	{
		A[i] = max(A[i], 0);
		A[i] = max(A[i], A[i+1]); // <=, not =
	}
	int mn = INT_MAX;
	for(int i = 0; i <= 1000001; i++)
	{
		mn = min(mn, i+A[i]);
	}
	cout << mn << endl;
}
