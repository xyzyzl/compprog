#include <bits/stdc++.h>

using namespace std;

int N, X[205], Y[205], aX[205], aY[205];
typedef pair<int, int> pii;
#define f first
#define s second
pii arr[205];

bool c1(int a, int b)
{
	return arr[a].f < arr[b].f;
}
bool c2(int a, int b)
{
	return arr[a].s < arr[b].s;
}

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> arr[i].f >> arr[i].s;
		X[i] = i;
		Y[i] = i;
	}
	sort(X, X+N, c1);
	sort(Y, Y+N, c2);
	for(int i = 0; i < N; i++)
	{
		aX[X[i]] = i;
		aY[Y[i]] = i;
	}
	if(N > 20)
	{
		cout << "placeholder" << endl;
	} else
	{
		int ans = 1;
		for(int i = 1; i < (1 << N); i++) {
			int mnx = INT_MAX, mny = INT_MAX, mxx = 0, mxy = 0;
			for(int j = 0; j < N; j++) {
				if(i & (1 << j)) {
					mnx = min(mnx, arr[j].f);
					mny = min(mny, arr[j].s);
					mxx = max(mxx, arr[j].f);
					mxy = max(mxy, arr[j].s);
				} 
			}
			int sl = max(mxy-mny, mxx-mnx);
			// cerr << mnx << " " << mny << " " << mxx << " " << mxy << endl;
			// try to fit the square along all four corners
			bool work = 0;
			if(sl == mxy-mny) for(int k = mxx-sl; k <= mnx; k++) {
				bool ok = 1;
				for(int j = 0; j < N; j++) {
					if(!(i & (1 << j))) {
						if(k <= arr[j].f && arr[j].f <= (k+sl) &&
							mny <= arr[j].s && arr[j].s <= (mxy))
							ok = 0;
					}
				}
				work |= ok;
			}
			if(sl == mxx-mnx) for(int k = mxy-sl; k <= mny; k++) {
				bool ok = 1;
				for(int j = 0; j < N; j++) {
					if(!(i & (1 << j))) {
						if(mnx <= arr[j].f && arr[j].f <= (mnx+sl) &&
							k <= arr[j].s && arr[j].s <= (k+sl))
							ok = 0;
					}
				}
				work |= ok;
			}
			ans += work;
		}
		cout << ans << endl;
	}
	
}