/*
What the ....... CHEESE -nukelauncher
WHAT the [expletive] ... *burps* -nukelauncher
*/

// bracketing ruined :(

#define MAXN 216

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
#define x first
#define y second

int N;
pii p[MAXN];

vector<int> v, va;

int bc[MAXN];

int main()
{
    freopen("lightsout.in", "r", stdin);
    freopen("lightsout.out", "w", stdout);
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> p[i].x >> p[i].y;
	}
	/** angles - casework on direction to and direction from **/
	for(int i = 1; i < N; i++)
	{
		int nx = i+1 >= N ? 0 : i+1;
		if(p[i].x-p[i-1].x > 0)
		{
			if(p[nx].y-p[i].y > 0)
			{
				// cout << 1 << endl;
				va.push_back(-2);
			}
			else
			{
				// cout << 2 << endl;
				va.push_back(-1);
			}
		}
		else if(p[i].x - p[i-1].x < 0)
		{
			if(p[nx].y-p[i].y > 0)
			{
				// cout << 3 << endl;
				va.push_back(-1);
			}
			else
			{
				// cout << 4 << endl;
				va.push_back(-2);
			}
		}
		else if(p[i].y - p[i-1].y > 0)
		{
			if(p[nx].x-p[i].x > 0)
			{
				// cout << 5 << endl;
				va.push_back(-1);
			}
			else
			{
				// cout << 6 << endl;
				va.push_back(-2);
			}
		}
		else if(p[i].y - p[i-1].y < 0)
		{
			if(p[nx].x-p[i].x > 0)
			{
				// cout << 7 << endl;
				va.push_back(-2);
			}
			else
			{
				// cout << 8 << endl;
				va.push_back(-1);
			}
		}
	}

	/** exit is -1 **/
	v.push_back(0);
	for(int i = 0; i < N; i++)
	{
		if(abs(p[(i+1) % N].y - p[i].y) > 0)
		{
			v.push_back(abs(p[(i+1) % N].y - p[i].y));
		}
		else if(abs(p[(i+1) % N].x - p[i].x) > 0)
		{
			v.push_back(abs(p[(i+1) % N].x - p[i].x));
		}
		v.push_back(va[(i) % N]);
	}
	// v.back() = 0;

	for(int i = 0; i < N; i++)
	{
		int dist = 0;
		for(int j = i; j < N; j++)
		{
			if(abs(p[(j+1) % N].x - p[j].x) > 0)
				dist += abs(p[(j+1) % N].x - p[j].x);
			else if(abs(p[(j+1) % N].y - p[j].y) > 0)
				dist += abs(p[(j+1) % N].y - p[j].y);
			// cout << dist << " a" << endl;
		}
		bc[i] = dist;
		dist = 0;
		for(int j = (i-1) % N; j >= 0; j--)
		{
			if(abs(p[(j+1) % N].x - p[j].x) > 0)
				dist += abs(p[(j+1) % N].x - p[j].x);
			else
				dist += abs(p[(j+1) % N].y - p[j].y);
			// cout << dist << " b" << endl;
		}
		bc[i] = i != 0 ? min(bc[i], dist) : 0;
		// cout << bc[i] << endl;
	}

	/*
	for(int i = 0; i <= N; i++)
	{
		cout << bc[i] << endl;
	}
	*/

	multiset<vector<int> > intv;
	for(int i = 0; i < v.size(); i+=2)
	{
		for(int j = 1; j <= v.size()-i; j+=2)
		{
			vector<int> path;
			for(int ind = i; ind < i+j; ind++)
			{
				path.push_back(v[ind]);
			}
			intv.insert(path);
			
			/*
			for(int k : path)
			{
				cout << k << " ";
			}
			cout << endl;
			*/
			
		}
	}

	int ans = -32394;
	for(int i = 2; i + 2 < v.size(); i+=2)
	{
		int j = -1, dist = 0;
		for(j = 1; ; j+=2)
		{
			vector<int> path;
			for(int ind = i; ind < i+j; ind++)
			{
				path.push_back(v[ind]);
				// cout << v[ind] << " ";
			}
			// cout << endl;
			// cout << intv.count(path) << " ";
			if(intv.count(path) == 1)
			{
				break;
			}
			dist += v[i + j];
			// cout << dist << endl;
		}
		// cout << endl;
		if(j != -1)
			ans = max(ans, dist + bc[(i + j)/2] - bc[i/2]);
	}
	cout << ans << endl;

}