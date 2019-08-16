#include <bits/stdc++.h>

using namespace std;

#define MAXN 5005

int n, arr[MAXN], dp[MAXN][MAXN];

int k(int i, int j)
{
    if(i > j) return 0;
    if(i == j) return arr[i];
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = max(min(k(i+2,j), k(i+1, j+1)) + arr[i], min(k(i+1, j-1), k(i, j-2)) + arr[j]);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < MAXN; i++) for(int j = 0; j < MAXN; j++) dp[i][j] = -1;
    cout << k(0, n-1) << endl;
}