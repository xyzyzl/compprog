#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		vector<int> freq[205];
		vector<int> num_inst[205];
		for(int i = 0; i < 205; i++)
		{
			freq[i].clear();
			num_inst[i].resize(n);
		}
		for(int i = 0; i < n; i++)
		{
			cin >> arr[i];
			freq[arr[i]].push_back(i);
			num_inst[arr[i]][i]++;
		}
		// psums!
		
		for(int k = 1; k <= 200; k++) for(int i = 1; i < n; i++)
		{
			num_inst[k][i] += num_inst[k][i-1];
		}
		// need to find each instance and loop through # instances
		int fin = 1;
		// cout << num_inst[2][7] << endl;
		for(int i = 1; i <= 200; i++)
		{
			// cerr << i << endl;
			for(int j = 0; j < freq[i].size(); j++)
			{
				if(freq[i].size()-1-j <= j) continue;
				// cerr << j << endl;
				// find maximum frequency in subarray from freq[i][j] to 
				// freq[i][freq[i].size()-1-j]
				int q = 0;
				for(int k = 1; k <= 200; k++)
				{
					q = max(q, num_inst[k][freq[i][freq[i].size()-1-j]-1] 
						- num_inst[k][freq[i][j]]);
				}
				int ans = 2*(j+1) + q;
				fin = max(fin, ans);
			}
			// cerr << i << endl;
		}
		cout << fin << endl;
	}
}