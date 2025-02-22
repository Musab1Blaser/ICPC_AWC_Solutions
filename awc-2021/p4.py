for _ in range(int(input())):
    n = int(input())
    s = input()
    m = int(input())
    malf = {}
    for i in range(m):
        a, b = input().split()
        malf[a] = b
    cur = 0
    valid = 1
    while cur < len(s) and valid:
        if s[cur] in malf:
            while s[cur] in malf:
                if cur+1 < len(s) and malf[s[cur]] == s[cur+1]:
                    cur += 1
                else:
                    print("NO")
                    valid = 0
                    break
        else:
            cur += 1
        if valid == 0:
            break
    else:
        print("YES")
            