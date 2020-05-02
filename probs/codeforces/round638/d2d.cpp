#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int a = 1;
		vector<int> moves;
		for(a = 1; a <= n; a*=2)
		{
			moves.push_back(a);
			n -= a;
		} // not only does 2^a <= n, sum of up to 2^a must also <= n
		if(n)
		{
			moves.push_back(n);
		}
		sort(moves.begin(), moves.end());
		vector<int> diff;
		for(int i = 0; i < moves.size()-1; i++)
		{
			diff.push_back(moves[i+1] - moves[i]);
		}
		cout << diff.size() << endl;
		for(int x : diff)
		{
			cout << x << " ";
		}
		cout << endl;
	}
}
