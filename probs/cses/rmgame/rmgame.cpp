#include <bits/stdc++.h>

using namespace std;

#define MAXN 5005

int n;
long long arr[MAXN], dp[MAXN][MAXN];

long long k(int i, int j)
{
    if(i > j) return 0;
    if(i == j) return arr[i];
    if(dp[i][j] != -1) return dp[i][j];
	return dp[i][j] = max(arr[i]-k(i+1,j), arr[j]-k(i,j-1));
}

int main()
{
    cin >> n;
	long long sum = 0;
	for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
		sum += arr[i];
    }
    for(int i = 0; i < MAXN; i++) for(int j = 0; j < MAXN; j++) dp[i][j] = -1;
    cout << (sum + k(0, n-1))/2 << endl;
}