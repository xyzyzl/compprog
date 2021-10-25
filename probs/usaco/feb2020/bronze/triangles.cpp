#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    // input N
    int n; cin >> n;
    // define X (stores all the points in the farm)
    vector<pair<int, int> > X(n);
    // takes in input for all the points
    for(int i = 0; i < n; i++) cin >> X[i].first >> X[i].second;
    // brute force through all triples of points x1, x2, x3???
    long long ans = 0;
    for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++) for(int k = j+1; k < n; k++)
    {
        // among X[i], X[j], X[k], the # of X-coordinates is 2 and the # of Y-coordinates is 2
        set<int> s1, s2; 
        s1.insert(X[i].first);
        s1.insert(X[j].first);
        s1.insert(X[k].first);
        s2.insert(X[i].second);
        s2.insert(X[j].second);
        s2.insert(X[k].second);
        // find that |s1| and |s2| are both 2
        if(s1.size() == 2 && s2.size() == 2)
        {
            ans = max(ans, (long long)(*s1.rbegin()-*s1.begin())*((*s2.rbegin()-*s2.begin())));
        }
    }
    cout << ans << endl;
}
