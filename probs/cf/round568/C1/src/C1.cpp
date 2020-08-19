#include <bits/stdc++.h>

using namespace std;

int n, m, arr[200005];
multiset<int> ms;
int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int sum = 0;
	for(int i = 0; i < n; i++) {
		int algeria = 0;
		if(m >= sum + arr[i]) {
			ms.insert(arr[i]);
			sum+=arr[i];
		}
		else {
			multiset<int> ms2 = ms;
			int tsum = sum;
			while(m < tsum + arr[i]) {
				algeria++;
				auto it = ms2.end();
				it--;
				int w = *it;
				tsum-=w;
				ms2.erase(it);
				// cout << tsum << endl;
			}
			sum += arr[i];
			ms.insert(arr[i]);
		}
		cout << algeria << " ";
	}
}
