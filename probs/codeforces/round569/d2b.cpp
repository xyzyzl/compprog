#include <bits/stdc++.h>

using namespace std;

int n, A[100005];
vector<pair<int, int> > V;
int main()
{
    cin >> n;
    int n_n=0;
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
        if(A[i] >= 0) A[i] = -A[i]-1;
        V.push_back(make_pair(A[i], i));
    }
    sort(V.begin(), V.end());
    if(n%2)
    {
        A[V[0].second] = -V[0].first-1;
    }
    for(int i = 0; i < n; i++) cout << A[i] << " ";
}