#include <cstdio>
#include <vector>
#include <iostream>
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		scanf("%d", &n);
		std::vector<int> a(n);
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		int lmost = -1, rmost = -1;
		for(int i = 0; i < n; i++)
		{
			if(a[i] != i+1) 
			{
				lmost = i;
				break;
			}
		}
		for(int i = n-1; i >= 0; i--)
		{
			if(a[i] != i+1)
			{
				rmost = i;
				break;
			}
		}
		if(lmost == -1)
		{
			printf("%d\n", 0);
			continue;
		}
		bool bad = 0;
		for(int i = lmost; i <= rmost; i++)
		{
			if(a[i] == i+1)
			{
				bad = 1;
				break;
			}
		}
		printf("%d\n", (bad ? 2 : 1));
	}
}
