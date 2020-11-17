fi = open("diamond.in", "r")
fo = open("diamond.out", "w")
n, k = fi.readline().split(' ')
n = int(n)
k = int(k)

a = [int(fi.readline()) for i in range(n)]
fi.close()
a.sort()

mx = [0 for i in range(n+1)] # maximum number of diamonds assuming i is the smallest diamond
j = 0
for i in range(n) :
	while j < n and a[j]-a[i] <= k :
		j+=1
	j -= 1	
	mx[i] = j-i+1

smx = [0 for i in range(n+1)] # suffix maximum
smx[n-1] = mx[n-1]
for i in range(n-2, -1, -1) :
	smx[i] = max(mx[i], smx[i+1])

ans = 0
for i in range(n) :
	ans = max(ans, mx[i] + smx[i+mx[i]])
fo.write(str(ans) + "\n")
fo.close()