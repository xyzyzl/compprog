#include <bits/stdc++.h>

#define PI 3.141592653585

using namespace std;

// num. cows, radius
int n, r;
// points array
pair<double, double> arr[50005];
// current segments
priority_queue<double, vector<double>, greater<double> > cur;
int main()
{
	freopen("sight.in", "r", stdin);
	freopen("sight.out", "w", stdout);
	scanf("%d %d", &n, &r);
	for(int i = 0; i < n; i++)
	{
		long long a, b;
		scanf("%lld %lld", &a, &b);
		// add line of sight angles, calculate through trig
		double theta = acos(r/sqrt(a*a+b*b));
		double x = atan2(b, a)-theta;
		if(x < 0) x += 2*PI;
		arr[i].first = x;
		arr[i].second = x+2*theta;
	}
	sort(arr, arr+n);
	int ans = 0;
	for(int iter = 0; iter < 2; iter++) for(int i = 0; i < n; i++)
	{
		// outside of each other's lines of sight
		while(cur.size() && (cur.top() < arr[i].first)) cur.pop();
		// add everything in line of sight
		if(iter)
		{
			ans += cur.size();
		}
		// add current point into intervals currently in next cow's
		// line of sight
		cur.push(arr[i].second);
		// add 2pi to each to account for wrap around 2pi
		arr[i].first += 2*PI;
		arr[i].second += 2*PI;
	}
	printf("%d\n", ans);
}
