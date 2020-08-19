#include <bits/stdc++.h>

using namespace std;

int MN;
int mdivs[500001];
int ndivs[500001];
// divs[i][j] is the list of i prime divisors of j
int divs[6][500001];
int main() {
	cin >> MN;
	// long long MN = max(M, N); // just consider MN as the maximum value you want to find factors of
	for (int i = 1; i <= MN; i++)
		ndivs[i] = 0;
	for (int i = 2; i <= MN; i++) {
		if (!ndivs[i]) {
			for (int j = i; j <= MN; j += i) {
				divs[ndivs[j]++][j] = i;
			}
		}
	}
	mdivs[1] = 1;
	for(int i = 2; i <= MN; i++)
	{
		mdivs[i] = i / divs[0][i];
	}
	sort(mdivs+1, mdivs+MN+1);
	for(int i = 2; i <= MN; i++) cout << mdivs[i] << " ";
	cout << endl;
}
