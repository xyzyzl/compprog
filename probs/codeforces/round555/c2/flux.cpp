// 27:50

#include <bits/stdc++.h>
using namespace std;

int n;
int arr[200005];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int l = 0, r = n - 1;
	vector<int> v;
	vector<int> v2;
	while (l <= r)
	{
		if (v.empty())
		{
			v2.push_back(min(arr[l], arr[r]));
			if (arr[l] < arr[r])
			{
				v.push_back('L');
				l++;
			}
			else if (arr[l] > arr[r])
			{
				v.push_back('R');
				r--;
			}
			else
			{
				int w = 1, e = 1;
				for (int i = l + 1; i < r; i++)
				{
					if (arr[i] <= arr[i - 1])
						break;
					w++;
				}
				for (int i = r - 1; i > l; i--)
				{
					if (arr[i] <= arr[i + 1])
						break;
					e++;
				}
				if (w > e)
					for (int i = 0; i < w; i++)
						v.push_back('L');
				else
					for (int i = 0; i < e; i++)
						v.push_back('R');
				break;
			}
			continue;
		}
		int w = v2.back();
		if (arr[l] < arr[r])
		{
			if (w >= arr[l])
			{
				if (w >= arr[r])
					break;
				v2.push_back(arr[r]);
				v.push_back('R');
				r--;
			}
			else
			{
				v2.push_back(arr[l]);
				v.push_back('L');
				l++;
			}
		}
		else if (arr[r] < arr[l])
		{
			if (w >= arr[r])
			{
				if (w >= arr[l])
					break;
				v2.push_back(arr[l]);
				v.push_back('L');
				l++;
			}
			else
			{
				v2.push_back(arr[r]);
				v.push_back('R');
				r--;
			}
		}
		else
		{
			if (w >= arr[r])
				break;
			if (l == r)
			{
				v.push_back('L');
				break;
			}
			int w = 1, e = 1;
			for (int i = l + 1; i < r; i++)
			{
				if (arr[i] <= arr[i - 1])
					break;
				w++;
			}
			for (int i = r - 1; i > l; i--)
			{
				if (arr[i] <= arr[i + 1])
					break;
				e++;
			}
			if (w > e)
				for (int i = 0; i < w; i++)
					v.push_back('L');
			else
				for (int i = 0; i < e; i++)
					v.push_back('R');

			break; // you know you are done by the end
		}
	}
	cout << v.size() << endl;
	for (char i : v)
		cout << i;
	return 0;
}