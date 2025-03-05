for _ in range(int(input())):
    n = int(input())
    h = list(map(int, input().split()))
    diff1 = h[1] - h[0] # increase at left
    diff2 = h[-1] - h[-2] # increase at right
    
    if n == 2 or diff2 >= diff1:
        print("YES")
    else:
        print("NO")