"""
Solution by Albert Ye
AlphaStar 2020 Summer Camp: CC31AB
Problem: jan09-backbarn
"""
# as specified in problem statement
r, c, k = input().split(' ')
r = int(r)
c = int(c)
k = int(k)

ans = 0
# can traverse to point
can = [ [True  for i in range(c)] for j in range(r) ]
# visited array
vis = [ [False for i in range(c)] for j in range(r) ]
for i in range(r) :
    s = input()
    for j in range(c) :
        if s[j] == 'T' :
            can[i][j] = False
# DFS solution: find all paths that end at the top-right corner
# and have length less than k via BFS. add 1 to the answer
# each time we achieve this
ans = 0
def dfs(x, y, d) :
    global ans
    # path too long
    if d > k :
        return
    # out of bounds
    if x < 0 or x >= r or y < 0 or y >= c :
        return
    # don't backtrack or hit a tree
    if vis[x][y] or not can[x][y] :
        return
    # add one to count if it's at the end
    if x == 0 and y == c-1 :
        ans += 1
        return
    # mark visited so Bessie doesn't retrace path
    vis[x][y] = True
    # dfs all possible next positions
    dfs(x+1, y, d+1)
    dfs(x, y+1, d+1)
    dfs(x-1, y, d+1)
    dfs(x, y-1, d+1)
    # unmark visited so Bessie can retraverse this point later
    vis[x][y] = False

# start dfs from lower-left corner
dfs(r-1, 0, 1)
print(ans)
