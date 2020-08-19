#include <iostream>
using namespace std;
int n,h,w,ct;
bool grid[505][505];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
void dfs(int x, int y, int dir) {
	if(!grid[x][y]) return;
	ct++;
	dfs(x+dx[dir], y+dy[dir], dir);
}

int main() {
	cin >> h >> w;
	for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) {
		char c;
		cin >> c;
		if(c=='*') {
			n++;
			grid[i][j] = 1;
		} else {
			grid[i][j] = 0;
		}
	}
	if(n >= h+w) {
		cout << "NO";
		return 0;
	}
	int startx=-1, starty=-1, flag=0;
	for(int i = 1; i < h-1; i++) for(int j = 1; j < w-1; j++) {
		if(grid[i][j] && grid[i-1][j] && grid[i+1][j] && grid[i][j-1] && grid[i][j+1]) {
			flag++;
			startx=i;
			starty=j;
		}
	}
	if(flag != 1) {
		cout << "NO";
		return 0;
	}
	for(int i = 0; i < 4; i++) {
		dfs(startx+dx[i], starty+dy[i], i);
	}
	ct++;
	// cout << ct << endl;
	if(ct != n) cout << "NO";
	else cout << "YES";
	return 0;
}