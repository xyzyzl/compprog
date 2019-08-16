#include <bits/stdc++.h>

using namespace std;

int b, k;
int a[100005];
int main()
{
    cin >> b >> k;
    for(int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    if(b%2==0)
    {
        cout << (a[k]%2 ? "odd" : "even") << endl;
    } else 
    {
        int num_of_odd_terms = 0;
        for(int i = 1; i <= k; i++)
        {
            if(a[i] % 2) num_of_odd_terms++;
        }
        cout << (num_of_odd_terms % 2 ? "odd" : "even") << endl;
    }
}