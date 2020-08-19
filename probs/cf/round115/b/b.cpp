#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;
int n, num_better[1005];
vector<pair<int, string> > A;
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        int j;
        cin >> s >> j;
        if(mp[s]) mp[s] = max(mp[s], j);
        else mp[s] = j;
    }
    for(pair<string, int> i : mp)
    {
        A.push_back(make_pair(i.second, i.first));
    }
    cout << A.size() << endl;
    sort(A.begin(), A.end());
    for(int i = A.size() - 1; i >= 0; i--)
    {
        num_better[i] = (i == A.size()-1) ? 0 : num_better[i+1];
        if(i != A.size()-1 && A[i].first < A[i+1].first) num_better[i] = (A.size()-1) - i;
        // cout << num_better[i] << endl;
    }
    for(int i = 1; i <= A.size(); i++)
    {
        int r = i-1;
        cout << A[r].second << " ";
        int rank = A.size() - num_better[r];
        if(rank * 100 >= A.size() * 99)
        {
            cout << "pro";
        } else if(rank * 100 >= A.size() * 90)
        {
            cout << "hardcore";
        } else if(rank * 100 >= A.size() * 80)
        {
            cout << "average";
        } else if(rank * 100 >= A.size() * 50)
        {
            cout << "random";
        } else cout << "noob";
        cout << endl;
    }
}