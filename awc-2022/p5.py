for _ in range(int(input())):
    n = int(input())
    s = input()
    i0, i1, j0, j1 = [-1]*4 # opt0 is zeros outer, opt1 is ones outer
    for i in range(n-1):
        if s[i] == '0' and s[i+1] == '1':
            if i0 == -1:
                i0 = i
            if i1 != -1 and i > i1:
                j1 = i 
        elif s[i] == '1' and s[i+1] == '0':
            if i1 == -1:
                i1 = i+1
            if i0 != -1 and i > i0+1:
                j0 = i + 1
                
    if j0 != -1:
        print(i0+1, j0+1, i0+2, j0)
    elif j1 != -1:
        print(i1+1, j1+1, i1, j1+2)
    else:
        print(-1)