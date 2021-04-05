#include <bits/stdc++.h>
using namespace std;
 
bool isPerfectSquare(long double x)
{
 
    long double sr = sqrt(x);
 
    return ((sr - floor(sr)) == 0);
}
 
bool isProduct(int num)
{
    int cnt = 0;
 
    for (int i = 2; cnt < 2 && i * i <= num; ++i) {
        while (num % i == 0) {
            num /= i;
            ++cnt;
        }
    }
    if (num > 1)
        ++cnt;
    return cnt == 2;
}
 
void findNumbers(int N)
{
	int count = 0;
    vector<int> vec;
    for (int i = 1; i <= N; i++) {
        if (isProduct(i) && !isPerfectSquare(i)) {
            ++count;
        }
    }
 
    cout << count;
}
 
// Driver function
int main()
{
    int n;
    cin >> n;
 
    findNumbers(n);
 
    return 0;
}
