import math

x = int(input())
ops = []

def ext_euc(a, b) :
    s = 0
    old_s = 1
    t = 1
    old_t = 0
    while a != 0 :
        q = b//a
        r = b%a
        m, n = old_s-s*q, old_t-t*q
        b,a,old_s,old_t,s,t = a,r,s,t,m,n
    return b,old_s,old_t

def get_mul(a, b) :
    base = a
    cur = 0
    while b > 0 :
        if b%2 == 1 :
            if cur > 0 :
                ops.append(str(cur) + ' + ' + str(base))
            cur += base
        ops.append(str(base) + ' + ' + str(base))
        base = 2*base
        b = b//2
    return cur

# find two coprime
e = math.floor(math.log2(x))
for i in range(e) :
    ops.append(str(x * (1 << i))+' + '+str(x * (1 << i)))
ops.append(str(x) + ' ^ ' + str((1 << e)*x))
y = ((1 << e)*x)^x
pair = ext_euc(x, -y)
p = pair[2]
q = pair[1]
while p < 0 or q < 0 :
    p += y
    q += x
if q % 2 == 1 : 
    p += y
    q += x
# print(p)
# print(q)
pro1=get_mul(x,p)
pro2=get_mul(y,q)
ops.append(str(pro1) + ' ^ ' + str(pro2))

print(len(ops))
for i in ops :
    print(i)
# print(p, q)
# print(y)
# print(x*p-y*q)
