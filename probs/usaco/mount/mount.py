"""
Solution by Albert Ye
AlphaStar 2020 Summer Camp: CC31AB
Problem: open10-mount
"""
n = int(input())
h = []
vis = []
for i in range(n) :
    h.append(int(input()))
    vis.append(False)
# so that it can detect mountains even when 
# the altimeter is totally flat
h.append(0)
vis.append(False)
# maximum length of a mountain
ans = 0
for i in range(n) :
    # if there is currently a decrease in altitude and 
    # we have not yet counted this mountain
    if (h[i+1] < h[i]) and (not vis[i]) :
        vis[i] = True
        # traverse left
        lo = i-1
        while lo >= 0 and h[lo] <= h[lo+1] :
            vis[lo] = True
            lo -= 1
        # traverse right
        hi = i+1
        while hi <  n and h[hi] <= h[hi-1] :
            vis[hi] = True
            hi += 1
        # check width
        # don't include hi or lo in the mountain
        ans = max(ans, hi-lo-1)

print(ans)

