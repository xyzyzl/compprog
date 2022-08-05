#include <bits/stdc++.h>
using namespace std; 
int main(){
	int n, m;
    cin >> n >> m;
	vector<int> a, d, v, u;
	for(int i = 0; i < n; i++){
        string s;
        int x;
        cin >> s >> x;
        if(s=="ATK") a.push_back(x);
        else d.push_back(x);
	}
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
	sort(a.begin(), a.end());
	sort(d.begin(), d.end());
	sort(v.begin(), v.end());
	int t = 0, p = 0, c = 0;
    for(int i = 0; i < m; i++) u.push_back(0);
	for(int i = 0; i < d.size(); i++){
		while(v[c]<=d[i]||u[c]){
			c++;
			if(c>=m){
				p = -999999999;
				break;
			}
		}
		if(c<m) u[c] = 1;
		else break;
	}
	if(p>-999999999){
		c = 0;
		for(int i = 0; i < a.size(); i++){
			while(v[c]<a[i]||u[c]){
				c++;
				if(c>=m){
					p = -999999999;
					break;
				}
			}
			if(c<m){
			    u[c] = 1;
				p+=v[c]-a[i];
			}
			else break;
		}
	}
	if(p>-999999999){
		for(int i = 0; i < m; i++){
             if(!u[i]) p+=v[i];
        }
    }
    if(p>t) t = p;	
	for(int i = 1; i <= min(m, int(a.size())); i++){
		int o = 0;
		for(int j = 0; j < i; j++){
			if(v[m-i+j]>=a[j]) o += v[m-i+j]-a[j];
			else o = -999999999;
		}
		t = max(t, o);
	}
	cout << t << endl;
}