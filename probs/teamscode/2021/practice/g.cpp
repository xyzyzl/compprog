#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;

	string cmax;
	int scr = -1;
	long long tscr = 0;

	for(int i = 0; i < n; i++)
	{
		string name; cin >> name;
		int avg, eval; cin >> avg >> eval;
		char c1, c2; cin >> c1 >> c2;
		int cad = (c1 == 'Y'), west = (c2 == 'Y');
		int ppr; cin >> ppr;
		int sc = (avg > 80 && ppr > 0) * 8000 + (avg > 85 && eval > 80) * 4000 + (avg > 90) * 2000 + west * 1000 + (cad && avg > 80) * 850;
		if(sc > scr)
		{
			scr = sc;
			cmax = name;
		}
		tscr += sc;
	}
	cout << cmax << endl;
	cout << scr << endl;
	cout << tscr << endl;
}
