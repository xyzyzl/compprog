#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int ans = INT_MAX;
		int _A = -1, _B = -1, _C = -1;
		for(int A = 1; A <= 2*a; A++)
		{
			for(int B = A; B <= 2*b; B+=A)
			{
				{
					int C = max(B, B * (c/B));
					if(abs(A-a) + abs(B-b) + abs(C-c) < ans)
					{
						_A = A;
						_B = B;
						_C = C;
					}
					ans = min(ans, abs(A-a) + abs(B-b) + abs(C-c));
				}
				{
					int C = max(B, B * (int) ceil((double)c/(double)B));
					if(abs(A-a) + abs(B-b) + abs(C-c) < ans)
					{
						_A = A;
						_B = B;
						_C = C;
					}
					ans = min(ans, abs(A-a) + abs(B-b) + abs(C-c));
				}
			}
		}
		printf("%d\n", ans);
		printf("%d %d %d\n", _A, _B, _C);
	}
}
