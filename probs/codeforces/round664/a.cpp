#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int r,g,b,w;
		cin>>r>>g>>b>>w;
		int x=r%2,y=g%2,z=b%2;
		int num = z+y*2+x*4;
		int A = __builtin_popcount(num);
		if(A == 0)
		{
			cout << "Yes" << endl;
		} else if(A == 1)
		{
			cout << (w%2==0 ? "Yes" : "No") << endl;
		} else if(A == 2)
		{
			cout << ((r>0&&g>0&&b>0&&w%2==1) ? "Yes" : "No") << endl;
		} else 
		{
			cout << ((r>0&&g>0&&b>0) ? "Yes" : "No") << endl;
		}
	}
}

