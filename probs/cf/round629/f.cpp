#include <bits/stdc++.h>

using namespace std;

#define MAXN 200005

int n, k, a[MAXN];
vector<pair<int, int> > cnt;
int pcnt[MAXN], scnt[MAXN];
long long psum[MAXN], ssum[MAXN];
int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	for(int i = 0; i < n; i++)
	{
		if(i == 0 || a[i] != a[i-1])
		{
			cnt.push_back({a[i], 1});
		} else 
		{
			cnt.back().second++;
		}
	}
	int m = (int)cnt.size();
	for(int i = 0; i < m; i++)
	{
		long long csum = (long long) cnt[i].first * (long long) cnt[i].second;
		int ccnt = cnt[i].second;
		if(i == 0) psum[i] = csum;
		else psum[i] = psum[i-1] + csum;
		if(i == 0) pcnt[i] = ccnt;
		else pcnt[i] = pcnt[i-1] + ccnt;
	}
	for(int i = m-1; i >= 0; i--)
	{
		long long csum = (long long) cnt[i].first * (long long) cnt[i].second;
		int ccnt = cnt[i].second;
		if(i == m-1) ssum[i] = csum;
		else ssum[i] = ssum[i+1] + csum;
		if(i == m-1) scnt[i] = ccnt;
		else scnt[i] = scnt[i+1] + ccnt;
	}
	long long ans = LLONG_MAX;
	for(int i = 0; i < m; i++)
	{
		int needed = max(0, k - cnt[i].second);
		if(needed == 0)
		{
			cout << 0 << endl;
			return 0;
		}
		int left = 0;
		if(i > 0) left = min(needed, pcnt[i-1]);
		int right = max(0, needed - left);
		long long res = 0;
		if(i > 0 && left > 0)
		{
			res += (long long) pcnt[i-1] * (long long) (cnt[i].first - 1) - psum[i-1];
			res += left;
		}
		if(i < m-1 && right > 0)
		{
			res += ssum[i+1] - (long long) scnt[i+1] * (long long) (cnt[i].first + 1);
			res += right;
		}
		ans = min(ans, res);

		right = 0;
		if(i < m-1) right = min(needed, scnt[i+1]);
		left = max(0, needed - right);
		res = 0;
		if(i > 0 && left > 0)
		{
			res += (long long) pcnt[i-1] * (long long) (cnt[i].first - 1) - psum[i-1];
			res += left;
		}
		if(i < m-1 && right > 0)
		{
			res += ssum[i+1] - (long long) scnt[i+1] * (long long) (cnt[i].first + 1);
			res += right;
		}
		ans = min(ans, res);
	}
	cout << ans << endl;
}
