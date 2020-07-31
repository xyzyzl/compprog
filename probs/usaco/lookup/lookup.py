"""
Solution by Albert Ye
AlphaStar Summer Camp 2020: CC31AB
Problem: mar09-lookup
"""
n = int(input())
# We can represent stacks as lists
st = []
ans = [0 for i in range(n)]
for i in range(n) :
    x = int(input())
    # while the stack isn't empty and there are
    # still cows before cow i shorter than cow i
    # and that haven't already been answered
    while len(st) > 0 and st[len(st)-1][0] < x :
        ans[st[len(st)-1][1]] = i+1
        st.pop()
    # add current cow to stack
    st.append([x, i])

for i in range(n):
    print(ans[i])
