#include <bits/stdc++.h>

using namespace std;

int N, A[100005];
bool vis[100005];
map<int, int> arr[100005];
vector<int> P;
int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for(int i = 2; i <= 100000; i++)
	{
		if(vis[i]) continue;
		P.push(i);
		for(int j = i; j <= 100000; j+=i)
		{
			vis[j] = 1;
		}
	}
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		for (int j = 2; j <= sqrt(a); j++)
		{
			while (a % j == 0)
				arr[i][j]++, a /= j;
		}
		arr[i][a]++;
	}
	for(int x : P)
	{
		cout << x << endl;
	}
}
