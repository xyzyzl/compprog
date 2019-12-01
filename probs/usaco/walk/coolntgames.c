#include <stdio.h>

int main()
{
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    int n,k;
    scanf("%d %d", &n,&k);
    printf("%d", 2019201997-84*(k-1)-48*n);
}