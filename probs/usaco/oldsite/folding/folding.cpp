// solution by Albert Ye
// AlphaStar 2020 Summer Camp: CC31AB
// Problem: feb12-folding
#include <bits/stdc++.h>

using namespace std;

// number of knots, length (not needed), position, difference between adjacent positions
int n, l, pos[105], diff[105];
int main()
{
	cin >> n >> l;
	for(int i = 0; i < n; i++) cin >> pos[i];
	sort(pos, pos+n); // sort the positions
	// and find the differences accordingly
	for(int i = 0; i < n-1; i++)
	{
		diff[i] = pos[i+1] - pos[i];
	}
	int ans = 0; // number of palindromes
	// check for palindromes on left and right
	for(int i = 0; i < n-1; i++)
	{
		bool works = 1;
		// 0 to i
		for(int j = 0; j <= i - j; j++)
		{
			if(diff[j] != diff[i-j])
			{
				works = 0;
				break;
			}
		}
		ans+=works;
	}
	for(int i = 1; i < n-1; i++)
	{
		bool works = 1;
		// i to n-2
		for(int j = 0; i + j <= n-2 - j; j++)
		{
			if(diff[i+j] != diff[n-2 - j])
			{
				works = 0;
				break;
			}
		}
		ans+=works;
	}
	cout << ans << endl;
}
