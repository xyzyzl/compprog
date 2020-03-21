int n, p[2005 * 2005], sz[2005 * 2005];

int find_set(int i)
{
    return (p[i] == i) ? i : (p[i] = find_set(p[i]));
}

bool union_set(int i, int j)
{
    int x = find_set(i);
    int y = find_set(j);
    if (x == y)
        return false;
    p[x] = p[y] = x;
    sz[x] += sz[y];
    return true;
}

int init()
{
    for(int i = 0; i < n; i++) p[i] = i;
    for(int i = 0; i < n; i++) sz[i] = 1;
}