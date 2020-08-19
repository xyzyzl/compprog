#include <iostream>
#include <cmath>

using namespace std;

long long n;
int main() {
	cin >> n;
	if(n%2) {
		cout << 0;
		return 0;
	}
	long long ans = 1;
	for(int i = 0; i < n/2; i++)
		ans *= 2;
	cout << ans;
	return 0;
}