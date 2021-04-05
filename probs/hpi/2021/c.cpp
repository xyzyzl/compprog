#include <bits/stdc++.h>

using namespace std;

int N;
int main()
{
	cin >> N;
	vector<int> A(N), B(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	for(int i = 0; i < N; i++) cin >> B[i];
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int S, T;
	cin >> S >> T;
	long long co = 0;
	for(int i = 0; i < N; i++)
	{
		if(A[i] < B[i]) co += S*(B[i]-A[i]);
		else            co += T*(A[i]-B[i]);
	}
	cout << co << endl;
}
