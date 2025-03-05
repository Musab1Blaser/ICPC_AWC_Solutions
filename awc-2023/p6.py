for _ in range(int(input())):
    n, r, s1, s2 = map(int, input().split())
    s1 -= 1
    s2 -= 1
    if s1 // 5 == s2 // 5:
        a = s1 % 5
        b = s2 % 5
        if b < a:
            a, b = b, a
        if (a == 0 and b == 1) or (a == 2 and b == 3) or (a == 3 and b == 4):
            print("yes")
            continue
    print("no")