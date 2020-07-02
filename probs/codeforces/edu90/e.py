t = int(input())

def solve(n, k):
    ans = -1
    for i in range(10):
        # print(i)
        m = n//9
        if i + k < 10:
            m = 0 # no need for extra 9's
        for j in range(m+1):
            if (i + k >= 10) and (j == 0):
                continue
            cur_sum = (i + (i+k)) * (k+1) // 2
            if j != 0 :
                before_turn = 10 - i
                after_turn = k+1 - before_turn
                cur_sum = (i+9) * before_turn // 2 + (1+after_turn) * after_turn // 2 + before_turn * 9 * (j - 1)
            rem = n - cur_sum # take remaining
            if (rem < 0) or (rem % (k+1) != 0):
                continue # remaining digits have to be used all k+1 times
            num = [i]
            for x in range(j-1): 
                num.append(9)
            mx = 9
            if i + k >= 10 :
                mx = 8
            rem = rem // (k+1)
            while rem != 0 :
                d = min(rem, mx)
                mx = 9
                rem -= d
                num.append(d)
            cur_best = 0
            for d in range(len(num)):
                cur_best += (10 ** d) * num[d]
            if ans == -1: ans = cur_best
            else: ans = min(ans, cur_best)
    print(ans)


for i in range(t):
    n, k = input().split(' ')
    n = int(n)
    k = int(k)
    solve(n, k)
