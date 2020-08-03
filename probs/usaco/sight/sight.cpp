#include <bits/stdc++.h>

using namespace std;

int n, r;
double arr[50005][2];
int main()
{
	scanf("%d %d", &n, &r);
	for(int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		double x = atan2(b, a);
		double theta = acos(R/sqrt(x*x+y*y));
		x * theta
