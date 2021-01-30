"""
Solution by Albert Ye
AlphaStar 2020 Summer Camp: CC31AB
Problem: mar10-mmind
"""
n = int(input())
hint = [] # list of hints
for i in range(n) :
    # each hint has a number and the number of correct/wrong guesses
    num, c, w = input().split(' ')
    c = int(c)
    w = int(w)
    hint.append([num,c,w])
# simulate for all 4-digit numbers
for num in range(1000, 10000) :
    # easier to treat as string
    tmp = str(num)
    works = True
    for x in range(n) :
        # whether or not each digit of the potential answer has been found
        m1 = [False, False, False, False]
        # whether or not each digit of the hint has been found
        m2 = [False, False, False, False]
        # sum and difference
        sm = 0
        df = 0
        # in same position
        for i in range(4) :
            if tmp[i] == hint[x][0][i] :
                sm += 1
                m1[i] = m2[i] = True
        # in different position
        for i in range(4) :
            if not m1[i] :
                for j in range(4) :
                    if (not m2[j]) and tmp[i] == hint[x][0][j] :
                        df += 1
                        m1[i] = m2[j] = True
        # check if number in same/different position is as expected
        if sm != hint[x][1] or df != hint[x][2] :
            works = False
            break
    # if it's as expected, print it and end
    if works :
        print(num)
        exit()
# if there are no solutions print NONE
print('NONE')
