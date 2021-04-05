#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
#define f first
#define s second

int N, M;
double dis[4005], dp[4005];
pii A[4005];

double ang(pii a)
{
	double x = a.f;
	double y = sqrt(a.f*a.f+a.s*a.s);
	return acos(x/y);
}

bool theta(pii a, pii b)
{
	return ang(a) < ang(b);
}

int main()
{
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
	{
		cin >> A[i].f >> A[i].s;
		dis[i] = sqrt(A[i].f*A[i].f+A[i].s*A[i].s);
	}
	A[0] = {1, 0};
	sort(A, A+N+1, theta);
	/*
	for(int i = 0; i <= N; i++)
	{
		cerr << A[i].f << " " << A[i].s << endl;
	}
	*/
	memset(dp, 0x7f, sizeof dp);
	dp[1] = dis[1]*sin(ang(A[1]));
	for(int i = 2; i <= N; i++)
	{
		for(int j = 1; j < i; j++)
		{
			dp[i] = min(dp[i], dp[j] + dis[i]*sin(ang(A[i])-ang(A[j])));
			cerr << i << " " << j << " " << dp[j] + dis[i]*sin(ang(A[i])-ang(A[j])) << endl;
		}
		cerr << dp[i] << endl;
	}
	cout << setprecision(3) << fixed << dp[N] << endl;
}
