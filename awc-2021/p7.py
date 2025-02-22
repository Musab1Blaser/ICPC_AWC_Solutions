for _ in range(int(input())):
    n, x = map(int, input().split())
    e = list(map(int, input().split()))
    rem_e = []
    cur_e = x
    floors = []
    for i in range(1, n+1):
        if e[-i] >= 0:
            cur_e += e[-i]
            floors.append(n + 1 - i)
        else:
            rem_e.append((e[-i], n + 1 -i))
    
    for f in rem_e:
        if cur_e + f[0] >= 0:
            cur_e += f[0]
            floors.append(f[1])
            
    print(len(floors))
    floors.sort()
    print(*floors)