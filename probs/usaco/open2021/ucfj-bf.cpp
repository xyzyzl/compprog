#include <bits/stdc++.h>

using namespace std;

int N, B[105];
int main()
{
	cin >> N;
	if(N <= 100)
	{
		for(int i = 0; i < N; i++)
		{
			cin >> B[i];
		}
		long long ans = 0;
		for(int i = 0; i < N; i++)
		{
			for(int j = i+1; j < N; j++)
			{
				if(B[i] == B[j]) continue;
				for(int k = i+1; k < j; k++)
				{
					if(B[i] != B[k] && B[j] != B[k])
					{

					} else
					{
						ans--; break;
					}
				}
				ans++;
			}
		}
		cout << ans << endl;
	} else 
	{
		cout << "HDFOISDHF" << endl;
	}
}