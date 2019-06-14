/// Need this for another problem, and general sieve implementation.
/// Managed to get this backed up before LMS closed

//============================================================================
// Name        : banner.cpp
// Author      : Albert Ye
// Version     : 1
// Copyright   : bash
// Description : Large Banner - time to go to arm10 00 00 00 00	fun
//============================================================================

// why i haven't given up on this question:
// http://www.wolframalpha.com/input/?i=Bagon+curve
// https://www.wolframalpha.com/input/?i=mrdue
// K miles of feed

#include <bits/stdc++.h>

using namespace std;

long long M, N, L, H, B;
long long ct;
// ndivs[i] is the number of prime divisors of i
int ndivs[100001];
// divs[i][j] is the list of i prime divisors of j
int divs[6][100001];
int main() {
	cin >> M >> N >> L >> H >> B;
	long long MN = max(M, N);
	for (int i = 1; i <= MN; i++)
		ndivs[i] = 0;
	for (int i = 2; i <= MN; i++) {
		if (!ndivs[i]) {
			for (int j = i; j <= MN; j += i) {
				divs[ndivs[j]++][j] = i;
			}
		}
	}
	long long mn = min(N, H);
	long long lo, hi;

	for (long long i = 1; i <= mn; i++) {
		lo = ceil(sqrt(max((long long)1, L * L - i * i)));
		hi = min(M, (long long) (sqrt(max((long long)0, H * H - i * i))));
		// unreachable circumstances, ignore to save time
		if (lo > hi || lo > M)
			continue;
		// every way to be divisible by a single prime
		// need to consider every ordering of primes

		// amount to subtract
		long long _ct = 0;
		// for each bitmask
		for (int j = 0; j < (1 << ndivs[i]); j++) {
			int pct = 1;
			long long _i = 1;
			int _j = j;
			for (int k = 0; k < ndivs[i]; k++) {
				if (_j & 1) {
					_i *= divs[k][i];
					_i %= B;
					pct = -pct;
				}
				_j = (_j >> 1);
			}
			long long HI = hi / _i;
			long long LO = (lo + _i - 1) / _i;
			_ct += pct
					* (((HI - LO + 1) * (M + 1)
							- _i * ((HI * (HI + 1) - (LO - 1) * LO) / 2)));
			_ct %= B;
		}
		ct += ((N - i + 1) * _ct);
		ct %= B;
	}
	ct = ct * 2 % B;
	if(L == 1) {
		ct += (M+1)*N + (N+1)*M;
		ct %= B;
	}
	while (ct < 0)
		ct += B;
	cout << ct % B << endl;
}
